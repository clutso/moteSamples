# Sodaq explorer

## Overview

The following Arduino project will setup your board to join a LoRa Network then read the temperature from ExpLoRer's integrated sensor and send the readings to the selected LNS. 

:warning: _**NOTE:** The following code has been adapted for educational porpouses. Some methods (like the ones related to payload formating) has been over-simplified to be more illustrative. This code is not recommended for Operative environments._

## Setup notes

This board uses arduino IDE to compile and upload the code. 

- The following url `http://downloads.sodaq.net/package_sodaq_samd_index.json` has to be added using the  _**File > preferences > aditional board managerURLs:**_ option. 

- You also have to target the right board by selecting  _**Tools > Board > SODAQ SAMD (32-bits ARM Cortex-M0+) Boards: > SODAQ ExpLoRer**_ 

- This code uses _Sodaq_RN2483.h_ and _Sodaq_wdt.h_ libraries which can be installed using the Arduino Library Manager. To do this you just have to select _**Tools > Library Manager...**_ , type the name of the libraries required in the search box, and once located click the "install" button.

- This code uses _loracredentials.h_ file* to store LoRa credentials (AppKey, DevEUI and AppEUI). This file contains the following lines: 

    ```
     #define DEVEUI "0000000000000000"
     #define APPEUI "0000000000000000"
     #define APPKEY "00000000000000000000000000000000"
    ```
  :eye: :grey_exclamation: --> **Edit _loracredentials.h_ file by replacing the zero values with your actual keys.** :key:  

- Compile and upload to the board.

- Enjoy 

Once the code has successfully uploaded the led will indicate some of the following satus:

| Led Pattern   |   Status                                  |
| ------------- |:-----------------------------------------:|
| Solid Blue    | Join request sent                         | 
| Red Blink     | Join REJECTED                             |
| Green blink   | Join ACCEPTED                             |
| Cyan  blink   | Data sent to LNS                          |
| Solid Yellow  | Warning: Module recoverable failure       |
| Solid Red     | Error: Module critcal failure             |
| Solid Mgenta  | Unexpected error (_oh noes.. :skull_and_crossbones:_ )       |

*_For security reasons _loracredentials.h_ file is _.gitignored_, so feel free to use your own keys._

_More details about the board:_

- https://support.sodaq.com/Boards/ExpLoRer/
- https://learn.sodaq.com/getting_started/
