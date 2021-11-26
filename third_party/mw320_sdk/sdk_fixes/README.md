Before  build the Matter NXP MW320 example, you need to install MW320 mcuxpresso at http://mcuxpresso.nxp.com.
Please follow the install step:
1. Create MW320 folder
    mkdir ~/Desktop/MW320
2. Set SDK environment
    export MW320_FOLDER=~/Desktop/MW320
3. Running patch_mw320_sdk.sh
    ~/connectedhomeip/third_party/mw320_sdk/sdk_fixes/patch_mw320_sdk.sh
4. Set SDK environment
    source ./connectedhomeip/third_party/mw320_sdk/sdk_fixes/set_env.sh

MW320_SDK_ROOT will be configured to build MW320 Matter application.

