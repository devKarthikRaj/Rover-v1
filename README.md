# Rover-v1
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20v1%20final%20take%202.jpg" alt="Rover v1 final take 2"></div><br>
<b>Rover v1 Documentation <br> 
Initial build completed on 21st January 2022.<br>
The inital build is a joystick controlled rover. <br>
Created for my own reference in the future and for any interested engineer wannabes (like myself) out there! <br> </b>

## Quick Reference
<b>Electrical</b> <br>
<i>Eagle PCBs</i> <br>
[Power Distribution Board](https://github.com/devKarthikRaj/Rover-v1/tree/master/Electrical/PCBs/Power%20Distribution%20Board/PDB%20v0) <br>
[Motor Driver](https://github.com/devKarthikRaj/Rover-v1/tree/master/Electrical/PCBs/Not%20in%20Use/Motor%20Driver/Rover%20MDrv%20v1) <br>
[Motor Controller](https://github.com/devKarthikRaj/Rover-v1/tree/master/Electrical/PCBs/Motor%20Controller/MCon%20v1) <br>
[Remote Control](https://github.com/devKarthikRaj/Rover-v1/tree/master/Electrical/PCBs/Remote%20Control/Rover%20Bt%20Remote) <br>

<i>Arduino Header Files</i> <br>
[Rover v1 Pin Configuration Header](https://github.com/devKarthikRaj/Rover-v1/tree/master/Electrical/Firmware/Arduino%20Libraries/roverV1) <br>

<i>Arduino Firmware</i> <br>
[Low Level Controller](https://github.com/devKarthikRaj/Rover-v1/tree/master/Electrical/Firmware/Low_Level_Controller_FW) <br>
[Motor Controller](https://github.com/devKarthikRaj/Rover-v1/tree/master/Electrical/Firmware/Motor_Controller_FW) <br>
[Remote Control](https://github.com/devKarthikRaj/Rover-v1/tree/master/Electrical/Firmware/Remote_Control_FW) <br>

<i>Overall Electrical System</i> <br>
[Block Diagram](https://github.com/devKarthikRaj/Rover-v1/blob/master/Electrical/Overall%20Electrical%20System/Overall%20Block%20Diagram/Overall%20Block%20Diagram.png) <br>
[Eagle Schematic](https://github.com/devKarthikRaj/Rover-v1/blob/master/Electrical/Overall%20Electrical%20System/Overall%20Schematic/Rover%20Overalls/Rover%20v1%20Overall.sch) <br>

<b>Mechanical</b> <br>
[Motor Mount Fusion 360 File](https://github.com/devKarthikRaj/Rover-v1/blob/master/Mechanical/Not%20in%20Use/Motor%20Mount%20v1.f3d) <br>
[Motor Mount GrabCAD](https://grabcad.com/library/gearbox-dc-motor-mount-1)<br>

___

# How it all came together
Warning - This is a long read! <br>

## I had been wanting to build something like this for quite a while now.  
I thought this would be easy and wouldn't take that long. Boy, was I wrong! Nevertheless, I had loads of fun doing this. Especially when everything worked! <br>

## A rocky start...
Kicked off the project by designing the mechanical aspect of the rover in Fusion 360 CAD. Initially decided to use those low cost yellow DC gear motors. YEAH I KNOW RIGHT, these motors are a pain to use just because they don't come with a mount, its not easy to mount these motors to ANYTHING! <br><br>
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Yellow%20DC%20gear%20motor.jpg" alt="Yellow DC gear motor" width=300></div> <br>

So, I went on to CAD out a mount for these motors. <br>
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mount%20CAD%20render.jpg" alt="Old motor mount CAD render" width=500></div> <br>

Eventually, I got the motor mounts 3D printed and assembled them. Functionality wise, these mounts were pretty good. Structurally, the screw holders at the side were too thin and broke off if stressed too much; but hey, the mounts got the job done... I'll let that pass! <br>
<div align="center">
    <img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mount%20one%20side%20take%201.jpg" alt="Old motor mount one side take 1" width=200> 
    <img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mount%20one%20side%20take%202.jpg" alt="Old motor mount one side take 2" width=200>
    <img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mount%20one%20side%20take%203.jpg" alt="Old motor mount one side take 3" width=200>
</div> <br>
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mounts.jpg" alt="Old motor motor mounts" width=500></div> <br>  
You can find these mounts on <a href="https://grabcad.com/library/gearbox-dc-motor-mount-1">GrabCAD</a> if you need the files. Feel free to use it. Give it a like too, that'll make my day! <br>

Motor mounts done. Need to mount them to something right? Its time to design the robot base. Came up with a race car/skateboard like shape for the base. <br>
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20rover%20chassis%20CAD%20render.jpg" alt="Old rover chassis CAD render" width=500></div> <br>

I laser cut the base and attached the motor mounts with the motor to the base. The chassis looked real good. <br> 
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20rover%20chassis%20in%20dev.jpg" alt="Old rover chassis in dev" width=500></div> <br>

I managed to complete only half the chassis though. Around this time, I graduated from school and lost access to all those wonderful machines (laser cutters, 3D printers, drills and stuff). Gone with the wind! There are 3D printing shops out there that offer low cost small scale printing for hobbyists like me! The problem was with finding a laser cutting shop or even a CNC shop for that matter - every place was expensive and only accepted large scale orders. Not hobbyist friendly. With a heavy heart... I discarded my beautiful half cooked chassis and took a break from the mechanical aspect. <br>

## A fresh start...
I started on the electrical aspect instead. My goal was to finish the electrical aspect first and then design the mechanical aspect accordingly to fit all the PCBs. Started out with the power circuit. 18650 Li-Ion batteries were my go to choice. Why? Surprisingly, 18650 Li-Ion batteries turned out to be cheaper than Li-Po batteries. Plus Li-Ion is better than Li-Po as they have a higher power density... More juice in a smaller form factor! Next, I knew I'd need to step down the battery voltage to two different voltages. 5V for the digital circuitry and 6V to 12V for the motors. This is where the project kind of stagnated for a while. I really wanted to design a SMD PCB for the power circuit. THT PMICs were outdated and dissipated too much power which essentially means that the chip gets really HOT. Hot ain't good. SMD it is! THT is a no go! I designed 3 to 4 SMD power PCBs and got them manufactured. Next came the soldering, this is were I ran into a wall. Struggled with SMD soldering. Especially the IC chips. Those things are evil. This took too much of my time. Flushed that down the drain as well! Did some cheating here, I decided to buy pre-made power regulator boards. One for each voltage I required. They worked flawlessly! I'll definitely return to SMD and SMD soldering soon, maybe with a reflow hot plate, but not for this project! <br>

Next comes the motor circuitry. Started by designing a motor driver using the L298N H-bridge motor driver IC chip. It worked on the first try! I got lucky I guess! I wanted to step things up a notch. So, I went on to design a motor controller PCB. Basically, a motor driver circuit accompanied by a microcontroller (MCU). The MCU enables other PCBs to communicate with the motor controller through SPI. The MCU basically makes the motor controller "smart". It now has a brain. 
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20controller%20take%201.jpg" alt="Motor controller" width=500> </div> <br><br> 

The motor controller has can be hooked up with an emergency stop (eStop) switch too.
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20controller%20eStop%20test.gif" alt="Motor controller eStop test"></div> <br> 
 
Motor controller in action:
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20controller%20main%20test.gif" alt="Motor controller in action"></div> <br>

### An emotional rollercoaster...
Sad story incoming. On top of all that, I also added a provision for an accelerometer module to be interfaced with the MCU on the motor controller board. The whole point of the accelerometer was to make the robot go straight. Supplying the exact same voltage to two motors of the same model will not make them spin at exactly the same rate. One motor "might" be slightly faster than the other. Every motor is different. The robot won't move in a straight line unless I have feedback control to ensure that the robot moves in a straight line. Instead of using a motor fitted with an encoder to measure distance travelled by each wheel and then feedback to the MCU to adjust accordingly, I thought of trying something new. Using an accelerometer module to measure the distance. This turned out to be extremely challenging. To obtain distance from an accelerometer, you'd have to double integrate and the result is extremely inaccurate. Espcially over time, the error increases exponentially. The accelerometer did work though. For the record, I managed to get data out of the accelerometer:
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20controller%20accelerometer%20test.gif" alt="Accelerometer in action"></div> <br> 
Since that was a dead end, I dropped the accelerometer and tried using a compass magnetometer module to measure heading. Then, orientate the robot accordingly if the robot is off course. Long story short, this turned out to be difficult as well. The compass outputs x,y,z axis values. With this I know which direction the robot is facing. However, translating this data into PWM commands to supply to the motor controller to adjust the heading of the robot proved to be challenging. I wanted to use PID control for this but I couldn't establish a link between the INPUT (magnetometer's x,y,z values) and the OUTPUT (PWM motor values). Ended up scrapping that idea as well. *Cry cry* <br> 
Pro tip - Best way to measure distance travelled by a robot is to use motors with encoders! I think I've learnt a very good lesson here :) <br> <br>

The only PCB left to work on was the PCB to distribute the two voltages to their own power rails so that the other PCBs can tap from these rails. Very simple. No complex circuits involved. This didn't take too long to get done.

## So done with the mechanical aspect...
Since I lost access to all those machines in school post graduation, I decided to get Tamiya parts. Tamiya has a lot of versatile products and its low cost, just what I was looking for. I also decided to use stronger motors. From a previous partially working obstacle sensor robot project, I knew that those yellow gear motors can't carry heavy loads. This robot was leaning on the heavier side. Especially with four 18650 batteries. So I bought some machifit gear motors, slightly more expensive than the yellow gear motors, but these machifit motors come with their own mount and nuts & bolts and can be hooked up to almost anything! How nice!  

Since the motor controller was an "overall" success and since I secured all the Tamiya mechanical parts from Japan and new motors from China, It was time to hook everything up. 
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20chassis%20in%20dev.jpeg" alt="Rover chassis in dev" width="500"></div> <br>

## A hot mess...
Yes. I know the whole rover sounds like a hot mess (not literally... my PCBs are cool as cucumbers). So, here's the block diagram of the rover's electrical system. The big picture:
<img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Electrical/Overall%20Electrical%20System/Overall%20Block%20Diagram/Overall%20Block%20Diagram.png" alt="Overall Electrical System Block Diagram">
The so called "low level controller (LLC)" here acts as a middle man. The low level controller is just an Arduino Mega board. The LLC communicates with the remote control for the rover via Bluetooth and sends the data received from the Bluetooth remote to the motor controller via SPI. In the future, if I add sensors to this rover, the sensors will also interact with the low level controller. The low level controller will process the sensor data and send control signals to the motor controller accordingly. Having the LLC will hopefully allow me to upgrade this rover hassle free in the future!   

The assembly was smooth as butter. The entire electrical system was wired up and "WORKING" on my table. That's what I'm talking about! Robot on table:
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Robot%20on%20table.gif" alt="Robot on table"></div> <br> 

Last but not least - the firmware for all the MCUs on the rover and the Bluetooth remote. Writing firmware is always fun. Even though I encountered half a million exceptions. I'm kidding. 
## Baby steps
The first time the rover moved...
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20baby%20steps.gif" alt="baby steps"></div> <br> 

## Rover gone mad
Bug filled code creating chaos...
<i>This was when I was still trying to control the robot using the accelerometer and magnetometer</i>
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20gone%20mad.gif" alt="Rover gone mad"></div> <br> 

## Rover in action!
It works!
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20in%20action.gif" alt="Rover in action"></div> <br>

Oh oh... I totally forgot about the remote control. It was still contained on a breadboard, running off my old Arduino Uno. Quickly made a THT PCB and got it manufactured and soldered. Took about a few hours to design the PCB in Eagle and 2 weeks for it to be delivered. Soldered it and boom! Done! One good thing that came about from creating so many failed PCBs - now I can whip up simple "WORKING" boards in a few hours... yay!
<div align="center">
    <img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Remote%20control%20no%20case%20take%201.jpg" alt="Remote control no case take 1" width="400">
    <img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Remote%20control%20no%20case%20take%202.jpg" alt="Remote control no case take 2" width="400">
</div>
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Remote%20control%20no%20case%20with%20rover.jpg" alt="Remote control no case with rover" width="400"></div> <br>

The remote control needed a case! Luckily I saved some unused 3D printed acrylic mounts from a school project a few years ago. Zip tied the remote control PCB and stuck the 9V battery to the mount.
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Remote%20control%20in%20case.jpg" alt="Remote control in case" width="500"></div> <br>

Stick a fork in it people! We done!
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20v1%20final%20take%201.jpg" alt="Rover v1 final take 1" width="500"></div>