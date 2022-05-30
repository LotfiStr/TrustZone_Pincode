# TrustZone_Pincode
This is a small application of TrustZone in STM32L5, in which we authentificate using a pin code stored in the secured area, you will find along side with this project a technical report <in french> in which we describe how the configuration and the procedure was done to achieve this.

 NOTES:
 LPUART1 is used to transfer data from the stm32l5 board to the terminal.
 USART3 is used to read the input data from the GUI.
 Think of changing the COM port in the GUI "executable_interface_pycharm" in order to ensure sending the data to the right port.
