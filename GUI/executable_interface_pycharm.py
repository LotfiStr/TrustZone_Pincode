"""PyClavier est un simple clavier qui utilise Python et PyQt5."""

import sys
from PyQt5 import QtCore, QtWidgets

# Importez QApplication et les widgets requis depuis PyQt5.QtWidgetso
from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QMainWindow
from PyQt5.QtWidgets import QWidget

# Importations pour la mise en forme du clavier
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGridLayout
from PyQt5.QtWidgets import QLineEdit
from PyQt5.QtWidgets import QPushButton
from PyQt5.QtWidgets import QVBoxLayout
from PyQt5 import uic
from functools import partial
import serial

########################################################################################
# Create a Controller class to connect the GUI and the model
class PyClavierCtrl:
    """PyCalc Controller class."""

    def __init__(self, view):
        """Controller initializer."""
        # model=self._evaluate
        self._view = view
        # Connect signals and slots
        self._connectSignals()

    def _Transmission(self):
        """Evaluate expressions."""
        # configure the serial connections (the parameters differs on the device you are connecting to)
        ser = serial.Serial('com16 ', 115200)
        if ser.isOpen():
            print("Serial port is open")

            data = self._view.displayText()  # data sent
            ser.write(str(data).encode('UTF-8'))
            ser.write(str('\n').encode('UTF-8'))

            print("you send data:", data)
            ser.close()

    def _buildExpression(self, sub_exp):
        """Build expression."""
        expression = self._view.displayText() + sub_exp
        self._view.setDisplayText(expression)

    def _connectSignals(self):
        """Connect signals and slots."""
        for btnText, btn in self._view.buttons.items():
            if btnText not in {'Entrer', 'C'}:
                btn.clicked.connect(partial(self._buildExpression, btnText))

        self._view.buttons['Entrer'].clicked.connect(self._Transmission)
        self._view.buttons['C'].clicked.connect(self._view.clearDisplay)

##########################################################################################""
# Create a subclass of QMainWindow to setup the calculator's GUI
class PyClavierUi(QMainWindow):

    # Snip
    def _createDisplay(self):
        """Create the display."""
        # Create the display widget
        self.display = QLineEdit()
        # Set some display's properties
        self.display.setFixedHeight(35)
        self.display.setAlignment(Qt.AlignRight)
        self.display.setReadOnly(True)
        # Add the display to the general layout
        self.generalLayout.addWidget(self.display)

    # Snip
    def setDisplayText(self, text):
        """Set display's text."""
        self.display.setText(text)
        self.display.setFocus()

    def displayText(self):
        """Get display's text."""
        return self.display.text()

    def clearDisplay(self):
        """Clear the display."""
        self.setDisplayText('')

    """PyClavier's View (GUI)."""

    def __init__(self):
        """View initializer."""
        super().__init__()
        # Set some main window's properties
        self.setWindowTitle('PyClavier')
        self.setFixedSize(235, 235)

        # creation du gestionnaire de mise en forme de type QVBoxLayout
        # Set the central widget and the general layout
        self.generalLayout = QVBoxLayout()

        # Set the central widget
        self._centralWidget = QWidget(self)
        self.setCentralWidget(self._centralWidget)

        self._centralWidget.setLayout(self.generalLayout)
        # Create the display and the buttons
        self._createDisplay()
        self._createButtons()

    def _createLogin(self):
        self.Login = QPushButton("Log in")
        LoginLayout = QGridLayout()
        Loginlayout.addWidget(self.Login[btnText])

    def _createButtons(self):
        """Create the buttons."""
        self.buttons = {}
        buttonsLayout = QGridLayout()
        # Button text | position on the QGridLayout
        buttons = {'7': (0, 0),
                   '8': (0, 1),
                   '9': (0, 2),
                   'C': (3, 2),
                   '4': (1, 0),
                   '5': (1, 1),
                   '6': (1, 2),
                   '1': (2, 0),
                   '2': (2, 1),
                   '3': (2, 2),
                   '0': (3, 0),
                   '00': (3, 1),
                   'Entrer': (2, 4)
                   }

        # Create the buttons and add them to the grid layout
        for btnText, pos in buttons.items():
            self.buttons[btnText] = QPushButton(btnText)
            self.buttons[btnText].setFixedSize(40, 40)
            buttonsLayout.addWidget(self.buttons[btnText], pos[0], pos[1])
            # Add buttonsLayout to the general layout
        self.generalLayout.addLayout(buttonsLayout)


######################################################################################

class Principal(QtWidgets.QMainWindow):

    def __init__(self, parent=None):
        """Initialise la fenêtre"""
        #uic.loadUi(r'C:\Users\ines\interface_STM32.ui',self)
        super(Principal, self).__init__()
        self.setWindowTitle(u"TrustZone log in")
        self.setFixedSize(400, 400)

        # mettre un fond (nécessaire avec un QMainWindow)
        self.setCentralWidget(QtWidgets.QFrame())

        # créer un bouton
        self.bouton = QtWidgets.QPushButton(u"Log in", self.centralWidget())
        self.bouton.clicked.connect(self.quelclient_m)

        # positionner les widgets sur le fond de la fenêtre
        posit = QtWidgets.QGridLayout()
        posit.addWidget(self.bouton, 1, 0)
        self.centralWidget().setLayout(posit)

    def quelclient_m(self):
        """Lance la deuxième fenêtre"""
        quelclient = PyClavierUi()
        test = PyClavierCtrl(quelclient)

        # la deuxième fenêtre sera 'modale' (la première fenêtre sera inactive)
        quelclient.setWindowModality(QtCore.Qt.ApplicationModal)

        # appel de la deuxième fenêtre
        quelclient.show()

    #############################################################################


if __name__ == "__main__":
    app = QApplication(sys.argv)
    main = Principal()
    main.show()
    sys.exit(app.exec_())
