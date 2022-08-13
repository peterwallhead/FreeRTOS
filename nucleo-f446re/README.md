# Installing STM32CubeIDE on Ubuntu 20.04.4 LTS

**Used to configure, build and run applications on the NUCLEO-F446RE development board (and other STM32 microcontrollers and microprocessors).**

1. Download the Generic Linux installer from https://www.st.com/en/development-tools/stm32cubeide.html
2. As per the instructions in [STM32CubeIDE installation guide - User manual](https://www.st.com/resource/en/user_manual/dm00603964-stm32cubeide-installation-guide-stmicroelectronics.pdf), run the installer and follow the prompts.

```sudo sh ./st-stm32cubeide_VERSION_ARCHITECHURE.PACKAGE```

where VERSION, ARCHITECTURE and PACKAGE must be entered after the selected Linux® package.

3. There is a [known bug](https://community.st.com/s/question/0D50X0000AgEAOdSQO/how-can-i-fix-could-not-determine-gdb-version-using-command-error-) that should have been fixed in the latest release but doesn't appear to have been. This means you'll need install an additional dependency:

```sudo apt install libncurses5*```   
