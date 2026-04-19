# How to Create a Custom Firmware Build (No-Code Workflow)

This repository is set up with a "Cloud Compiler" that lets you create a personalized firmware for your OnStepX controller without installing any software. All you need is a free GitHub account.

Follow these steps to customize and build your firmware:

### Step 1: Fork the Repository

Click the **"Fork"** button at the top-right of this page. This will create your own personal copy of the OnStepX code under your GitHub account.

### Step 2: Enable GitHub Actions

In your new forked repository, go to the **"Actions"** tab. You will see a message saying "Workflows aren't configured". Click the green button that says **"I understand my workflows, go ahead and enable them."**

### Step 3: Edit Your Configuration

1.  Navigate to the `src/` folder and click on the **`Config.h`** file. You can also edit `Extended.config.h` if needed.
2.  Click the **pencil icon** (✏️) in the top-right corner of the file viewer to edit the file.
3.  Make your desired changes. For example, change the `#define PINMAP` to match your specific hardware.
4.  Once you are done, click the green **"Commit changes..."** button at the top-right. You can leave the default commit message.

### Step 4: Download Your Firmware

Committing the change automatically triggers the build process!

1.  Click on the **"Actions"** tab again. You will see a workflow running with the name of your commit (e.g., "Update Config.h").
2.  Wait for the process to complete (it usually takes 1-2 minutes). When it is done, a green checkmark (✅) will appear.
3.  Click on the completed workflow's name to go to the summary page.
4.  On the summary page, you will find a **Job Summary** with instructions and a link to the web flasher.
5.  Scroll to the bottom of the page to the **"Artifacts"** section. You will see a file named `firmware-esp32`.
6.  Click the **download icon** to download the `firmware-esp32.zip` file.

### Step 5: Flash Your Firmware

1.  Unzip the downloaded file. It will contain a single file named `firmware-factory.bin`.
2.  Go to the **[OnStepX Web Flasher](https://graydigitalarts.com/OnStep-Web-Tools/custom-flasher.html)**.
3.  Select the `firmware-factory.bin` file you just extracted.
4.  Follow the on-screen instructions to connect to your ESP32 and flash the firmware.

That's it! If the main OnStepX code is ever updated, you will see a banner on your fork telling you it's behind. Just click **"Sync fork"** and the process will run again, giving you a new `.bin` file with all the latest updates.

---

OnStepX Telescope Controller
===========================

# What is OnStepX?
OnStepX is the advanced version of the OnStep computerized telescope controller with support for interfacing with/controlling a variety of motor drivers (and so motors) including Step/Dir, ODrive, and Servo (a combination of encoder and DC motor or Stepper motor) types.

It supports:
* Telescope Mount control (Alt/Azm and Equatorial GEM/Fork.)  Optional support for Eq mounts with Tangent Arm Declination.  Usually the Goto capability is enabled, but that's optional as well for those who just want basic mount control.
* Telescope Rotator control (including Alt/Azm de-rotation.)
* Telescope Focuser control (up to 6 focusers so it can handle collimation as well as focusing.)
* Telescope Accessory control (combination of up to 8 dew-heaters, switches, analog PWM.)

# Features
OnStepX supports a wide variety of connection options.  Several serial
"command channels" can be utilized. One of the these is normally devoted to a USB
connection and for the other(s) choose from the following:

* Bluetooth
* ESP8266 WiFi
* Arduino M0/Ethernet Shield
* Even another USB port or RS232 serial isn't very difficult to add.

In the case of running OnStepX on an ESP32 it can provide its own Bluetooth or WiFi IP command channels without additional hardware by simply activating the feature in OnStepX.

Other software in the OnStep ecosystem include:

* an [ASCOM](http://ascom-standards.org/) driver (with IP and Serial support),
* an Android App useable over WiFi or Bluetooth equipped Phones/Tablets,
* a "built-in" website (on the Ethernet and/or WiFi device),
* a full planetarium program that controls all features ([Sky Planetarium](http://stellarjourney.com/index.php?r=site/software_sky)).

OnStep is compatible with the LX200 protocol. This means it can be controlled
from other planetarium software, like: Sky Safari, CdC (even without ASCOM),
Stellarium, etc.

There are also [INDI](http://www.indilib.org/about.html) drivers so it can be used from Linux, with CdC or KStars.

# Documentation
Detailed documentation, including the full set of features, detailed designs for
PCBs, instructions on how to build a controller, how to configure the firmware
for your particular mount, can all be found the [OnStep Group Wiki](https://groups.io/g/onstep/wiki/home).

# Change Log
All the changes are tracking in git, and a detailed list can be accessed using the
following git command:
 
git log --date=short --pretty=format:"%h %ad %<(20)%an %<(150,trunc)%s"

# Support
Questions and discussion should be on the mailing list (also accessible via the
web) at the [OnStep Group](https://groups.io/g/onstep/).

# License
OnStep is open source free software, licensed under the GPL.

See [LICENSE.txt](./LICENSE.txt) file.

# Author
[Howard Dutton](http://www.stellarjourney.com)

