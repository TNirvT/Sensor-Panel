# Sensor-Panel
Rainmeter Sensor Panel: Hardware monitoring

- Requirements: Rainmeter, HWInfo, Intel PresentMon.

Utilize HWInfo and Intel PresentMon to monitor hardware sensors: CPU (load percentage, clock, temperature, power), GPU (load percentage, clock, temperature, power), Coolant temperature (from mobo temperature sensor pin), frame per second, chassis fan speeds, network upload and download speeds, memory (system and video) load percentage, also time and date.

HWInfo has 2 options (current version v8.28 as of writing), shared memory (readings are located in RAM) and gadget (which is no longer supported in Win11, but the app still writes and updates data to registry keys). All the measures are located in @Resources/Addons/measures.inc file, this Rainmeter use the shared memory way. An example comparing both options as shown below. More information available on Rainmeter official documentation (https://docs.rainmeter.net/tips/hwinfo/).
- Using Shared Memory
```
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf0000300
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x7000011
HWiNFOType=CurrentValue
```
- Using Gadget
```
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value58
```

Screenshot
![Screenshot](@Resources/Imgs/Screenshot.jpg)
