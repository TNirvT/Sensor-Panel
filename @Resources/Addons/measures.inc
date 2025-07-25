[Variables]

;   Memory/RAM
[Measure_RAM_Used]
Measure=PhysicalMemory

[Measure_RAM_Used_Calc]
Measure=Calc
Formula=Measure_RAM_Used / 1024 / 1024 / 1024

[Measure_RAM_Free]
Measure=PhysicalMemory
InvertMeasure=1

[Measure_RAM_Free_Calc]
Measure=Calc
Formula=Measure_RAM_Free / 1024 / 1024 / 1024

[Measure_RAM_Total]
Measure=Calc
Formula=Measure_RAM_Free_Calc + Measure_RAM_Used_Calc
UpdateDivider=-1

[Measure_RAM_Load_Percentual]
Measure=Calc
Formula=(Measure_RAM_Used_Calc / Measure_RAM_Total) * 100
NumOfDecimals=0

;   HWiNFO
[Measure_CPU_Clock]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf0000300
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x6000022
HWiNFOType=CurrentValue

[Measure_CPU_Load]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf0000300
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x7000011
HWiNFOType=CurrentValue

[Measure_CPU_Temp]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf0000501
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x1000000
HWiNFOType=CurrentValue

[Measure_CPU_Power]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf0000501
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x5000000
HWiNFOType=CurrentValue

[Measure_Coolant_Temp]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf7067010
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x100000f
HWiNFOType=CurrentValue

[Measure_GPU_Clock]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xe0002000
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x6000000
HWiNFOType=CurrentValue

[Measure_GPU_Temp]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xe0002000
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x1000000
HWiNFOType=CurrentValue

[Measure_GPU_Load]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xe0002000
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x7000000
HWiNFOType=CurrentValue

[Measure_GPU_Power]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xe0002000
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x5000000
HWiNFOType=CurrentValue

[Measure_Fps]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf0000ff0
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x800000a
HWiNFOType=CurrentValue

[Measure_Fan1_Speed]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf7067010
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x3000000
HWiNFOType=CurrentValue

[Measure_Fan2_Speed]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xf7067010
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x3000002
HWiNFOType=CurrentValue

[Measure_VRAM_Free]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xe0002000
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x80000fb
HWiNFOType=CurrentValue

[Measure_VRAM_Used]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=0xe0002000
HWiNFOSensorInstance=0x0
HWiNFOEntryId=0x80000fc
HWiNFOType=CurrentValue

;   Gauges
[Measure_CPU_Load_Gauge]
Measure=Calc
Formula=Measure_CPU_Load
MinValue=0
MaxValue=100

[Measure_CPU_Load_Gauge_Yellow]
Measure=Calc
Formula=Measure_CPU_Load
MinValue=70
MaxValue=85

[Measure_CPU_Load_Gauge_Red]
Measure=Calc
Formula=Measure_CPU_Load
MinValue=85
MaxValue=100

[Measure_CPU_Temp_Gauge]
Measure=Calc
Formula=Measure_CPU_Temp
MinValue=25
MaxValue=90
IfCondition=Measure_CPU_Temp_Gauge > 75
IfTrueAction=[!SetOption Meter_CPU_Temp_Text FontColor "#WarnRed#"]
IfCondition2=(Measure_CPU_Temp_Gauge > 60) && (Measure_CPU_Temp_Gauge <= 75)
IfTrueAction2=[!SetOption Meter_CPU_Temp_Text FontColor "#WarnYellow#"]
IfCondition3=Measure_CPU_Temp_Gauge <= 60
IfTrueAction3=[!SetOption Meter_CPU_Temp_Text FontColor "#FontColor#"]

[Measure_CPU_Power_Gauge]
Measure=Calc
Formula=Round(Measure_CPU_Power)
MinValue=0
MaxValue=88

[Measure_Coolant_Temp_Gauge]
Measure=Calc
Formula=Measure_Coolant_Temp
MinValue=25
MaxValue=40
IfCondition=Measure_Coolant_Temp_Gauge > 38
IfTrueAction=[!SetOption Meter_Coolant_Temp_Text FontColor "#WarnRed#"]
IfCondition2=(Measure_Coolant_Temp_Gauge > 35) && (Measure_Coolant_Temp_Gauge <= 38)
IfTrueAction2=[!SetOption Meter_Coolant_Temp_Text FontColor "#WarnYellow#"]
IfCondition3=Measure_Coolant_Temp_Gauge <= 35
IfTrueAction3=[!SetOption Meter_Coolant_Temp_Text FontColor "#FontColor#"]

[Measure_GPU_Load_Gauge]
Measure=Calc
Formula=Measure_GPU_Load
MinValue=0
MaxValue=100

[Measure_GPU_Load_Gauge_Yellow]
Measure=Calc
Formula=Measure_GPU_Load
MinValue=70
MaxValue=85

[Measure_GPU_Load_Gauge_Red]
Measure=Calc
Formula=Measure_GPU_Load
MinValue=85
MaxValue=100

[Measure_GPU_Temp_Gauge]
Measure=Calc
Formula=Measure_GPU_Temp
MinValue=25
MaxValue=90
IfCondition=Measure_GPU_Temp_Gauge > 75
IfTrueAction=[!SetOption Meter_GPU_Temp_Text LineColor "#WarnRed#"]
IfCondition2=(Measure_GPU_Temp_Gauge > 60) && (Measure_GPU_Temp_Gauge <= 75)
IfTrueAction2=[!SetOption Meter_GPU_Temp_Text LineColor "#WarnYellow#"]
IfCondition3=Measure_GPU_Temp_Gauge <= 60
IfTrueAction3=[!SetOption Meter_GPU_Temp_Text LineColor "#AccentColor#"]

[Measure_GPU_Power_Gauge]
Measure=Calc
Formula=Round(Measure_GPU_Power)
MinValue=0
MaxValue=400

[Measure_Fps_Gauge]
Measure=Calc
Formula=Measure_Fps
MinValue=0
MaxValue=90

[Measure_Fps_Gauge_Yellow]
Measure=Calc
Formula=Measure_Fps
MinValue=(90*0.7)
MaxValue=(90*0.85)

[Measure_Fps_Gauge_Red]
Measure=Calc
Formula=Measure_Fps
MinValue=(90*0.85)
MaxValue=90

[Measure_Fan1_Speed_Gauge]
Measure=Calc
Formula=Measure_Fan1_Speed
MinValue=0
MaxValue=2000

[Measure_Fan2_Speed_Gauge]
Measure=Calc
Formula=Measure_Fan2_Speed
MinValue=0
MaxValue=2000

[Measure_VRAM_Free_Calc]
Measure=Calc
Formula=Measure_VRAM_Free / 1024

[Measure_VRAM_Used_Calc]
Measure=Calc
Formula=Measure_VRAM_Used / 1024

[Measure_VRAM_Load_Bar]
Measure=Calc
Formula=Measure_VRAM_Used_Calc / (Measure_VRAM_Used_Calc + Measure_VRAM_Free_Calc)

[Measure_VRAM_Load_Percentual]
Measure=Calc
Formula=Measure_VRAM_Load_Bar * 100

;   Time
[Measure_Time]
Measure=Time
Format=%#I:%M:%S %p  %A, %F

[Measure_UL]
Measure=NetOut
UseBits=1
MinValue=0
MaxValue=1000000000

[Measure_DL]
Measure=NetIn
UseBits=1
MinValue=0
MaxValue=1000000000
