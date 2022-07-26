# FreeRTOS

My playground for learning how to advance my projects using with C and FreeRTOS.

Starting with the [SMP Demos for the Raspberry Pi Pico Board](https://www.freertos.org/smp-demos-for-the-raspberry-pi-pico-board.html)

## Installing the Pico SDK on Ubuntu 20.04.4 LTS
### 1. Get the SDK and examples
Stay organised by creating a new directory called ```pico```. For me this gave me the path of ```/home/peter/pico``` (**this will be important later**).

```
$ cd ~/
$ mkdir pico
$ cd pico
```
Then clone the ```pico-sdk``` and ```pico-examples``` git repositories.

```
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git
```

### 2. Install the Toolchain
To build the applications in ```pico-examples```, you'll need to install some extra tools. To build projects you'll need ```CMake```, a cross-platform tool used to build the software, and the ```GNU Embedded Toolchain for Arm```. You can install both these via ```apt``` from the command line. Anything you already have installed will be ignored by ```apt```.

```
$ sudo apt update
$ sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
```

## Building "read_gpio" from this repo
```pico/pico-examples/read_gpio``` is a quick example of how to read a GPIO pin in C on a Pico.

Clone this repo.
```
$ git clone https://github.com/peterwallhead/FreeRTOS
```

Navigate into ```pico-examples``` and create a build directory

```
$ cd FreeRTOS/pico/pico-examples
$ mkdir build
$ cd build
```

Export the absolute path to where you installed the ```pico-sdk```. For me this was ```/home/peter/pico/pico-sdk```. *You'll need to do this for every new Terminal session.*

```
$ export PICO_SDK_PATH=/home/peter/pico/pico-sdk
```

Prepare your cmake build directory by running ```cmake ..```
```
$ cmake ..
Using PICO_SDK_PATH from environment ('/home/peter/pico/pico-sdk')
PICO_SDK_PATH is /home/peter/pico/pico-sdk
  .
  .
  .
-- Build files have been written to: /home/peter/Dev/FreeRTOS/pico/pico-examples/build
```

CMake has now prepared a build area for the ```pico-examples``` tree. From here, it is possible to type ```make``` to build all the example applications. However, as we are building ```read_gpio``` we will only build that application for now by changing directory into the ```read_gpio``` directory before typing ```make```.

**TIP:** Depending on the number of cores available on your machine, you may be able to speed up the ```make``` process by running it in parallel. To do this us ```-j``` followed by the selected number of cores. For example, ```-j4``` will run four jobs.

```
$ cd read_gpio
$ make
Scanning dependencies of target ELF2UF2Build
Scanning dependencies of target boot_stage2_original
[ 0%] Creating directories for 'ELF2UF2Build'
  .
  .
  .
[100%] Linking CXX executable read_gpio.elf
[100%] Built target read_gpio   
```

Amongst other targets, we have now built:
- read_gpio.elf, which is used by the debugger
- read_gpio.uf2, which can be dragged onto the RP2040 USB Mass Storage Device

## Load and run "read_gpio"

The fastest method to load software onto a RP2040-based board for the first time is by mounting it as a USB Mass Storage Device. Doing this allows you to drag a file onto the board to program the flash. Go ahead and connect the
Raspberry Pi Pico to your Linux machine using a micro-USB cable, making sure that you hold down the ```BOOTSEL``` button as you do so, to force it into USB Mass Storage Mode.

The Raspberry Pi Pico should automatically mount as a USB Mass Storage Device. From here, you can Drag-and-drop ```FreeRTOS/pico/pico-examples/build/read_gpio.uf2``` onto the Mass Storage Device. RP2040 will reboot, unmounting itself as a Mass Storage Device, and start to run the flashed code.

## Using "read_gpio"

Connecting a jumper wire between GPIO pin 19 and 3V3 pin will turn the onboard LED on. While this jumper wire is disconnected, the onboard LED will stay off.

## Helpful docs

[Getting started with Raspberry Pi Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf) - Used to install the Pico SDK and build Toolchain
