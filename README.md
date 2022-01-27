# Rover-v1
Remote Control Rover (Rover v1) Documentation <br> 
Build completed on 21st January 2022. <br>
Created for my own reference in the future and for any interested engineer wannabes (like myself) out there! <br>
Warning - This is a long read! <br>

## I had been wanting to build something like this for quite a while now.  
I thought this would be easy and wouldn't take that long. Boy, was I wrong! Nevertheless, I had loads of fun doing this. Especially when everything worked! <br>

## A rocky beginning...
Kicked off the project by designing the mechanical aspect of the rover in Fusion 360 CAD. Initially decided to use those low cost yellow DC gear motors. YEAH I KNOW RIGHT, these motors are a pain to use just because they don't come with a mount, its not easy to mount these motors to ANYTHING! <br><br>
<div align="center"><img src="https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Yellow%20DC%20gear%20motor.jpg" alt="Yellow DC gear motor" width = 300></div> <br>

So, I went on to CAD out a mount for these motors. <br>
![Old motor mount CAD render](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mount%20CAD%20render.jpg | width = 500) <br>

Eventually, I got the motor mounts 3D printed and assembled them. Functionality wise, these mounts were pretty good. Structurally, the screw holders at the side were too thin and broke off if stressed too much; but hey, the mounts got the job done... I'll let that pass! <br>
![Old motor mount one side take 1](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mount%20one%20side%20take%201.jpg | width = 100) 
![Old motor mount one side take 2](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mount%20one%20side%20take%202.jpg | width = 100)
![Old motor mount one side take 3](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mount%20one%20side%20take%203.jpg | width = 100) <br> 
![Old motor motor mounts](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20motor%20mounts.jpg | width = 500) <br>
You can find these mounts on [GrabCAD](https://grabcad.com/library/gearbox-dc-motor-mount-1) if you need the files. Feel free to use it. Give it a like too, that'll make my day! <br>

Motor mounts done. Need to mount them to something right? Its time to design the robot base. Came up with a race car/skateboard like shape for the base. <br> 
![Old rover chassis CAD render](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20rover%20chassis%20CAD%20render.jpg | width = 500) <br>

I laser cut the base and attached the motor mounts with the motor to the base. This chassis looked pretty damn good. <br>
![Old rover chassis in dev](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Old%20rover%20chassis%20in%20dev.jpg | width = 500) <br>
I managed to complete only half the chassis though. Around this time, I graduated from school and lost access to all those wonderful machines(laser cutters, 3D printers, drills and stuff). Gone with the wind! There are 3D printing shops out there that offer low cost small scale printing for hobbyists like me! The problem was with finding a laser cutting shop or even a CNC shop for that matter - every place was expensive and only accepted large scale orders. Not hobbyist friendly. With a heavy heart... I discarded my beautiful half cooked chassis and took a break from the mechanical aspect. <br>

## A fresh start...
I started on the electrical aspect instead. My goal was to finish the electrical aspect first and then design the mechanical aspect accordingly to fit all the PCBs. Started out with the power circuit. 18650 Li-Ion batteries were my go to choice. Why? Surprisingly, 18650 Li-Ion batteries turned out to be cheaper than Li-Po batteries. Plus Li-Ion is better than Li-Po as they have a higher power density... More juice in a smaller form factor! Next, I knew I'd need to step down the battery voltage to two different voltages. 5V for the digital circuitry and 6V to 12V for the the motor. This is where the project kind of stagnated for a while. I really wanted to design a SMD PCB for the power circuit. THT PMICs were outdated and dissipated too much power which essentially means the chip gets really HOT. Hot ain't good. SMD it is! THT is a no go! I designed 3 to 4 SMD power PCBs and got them manufactured. Next came the soldering, this is were I ran into a wall. Struggled with SMD sodlering. Especially the IC chips. Those things are evil. This took too much of my time. Flushed that down the drain as well! Did some cheating here, I decided to buy pre-made power regulator boards. One for each voltage I required. They worked flawlessly! I'll definitely return to SMD and SMD soldering soon, maybe with a reflow hot plate, but not for this project! <br>

Next comes the motor circuitry. Started by designing a motor driver using the L298N H-bridge motor driver IC chip. It worked on the first try! I got lucky I guess! I wanted to step things up a notch. So, I went on to design a motor controller motor driver with a microcontroller (MCU) onboard the PCB). 
The motor controller has can be hooked up with an emergency stop (eStop) switch.
![Motor controller eStop test](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20controller%20eStop%20test.gif | width = 100) 
Commands can be sent to the motor controller via SPI. It also comes with LED power and eStop indicators.
![Motor controller take 1](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20controller%20take%201.jpg | width = 500) <br>
![Motor controller take 2](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20Controller%20take%202.jpg | width = 500) <br>
[Motor controller in action](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20controller%20main%20test.gif | width = 100)<br>

### An emotional rollercoaster...
Sad story incoming. On top of all that, I also added a provision for an accelerometer module to be interfaced with the MCU on the motor controller board. The whole point of the accelerometer was to make the robot go straight. Supplying the exact same voltage to two motors of the same model will not make them spin at exactly the same rate. One motor "might" be slightly faster than the other. Every motor is different. The robot won't move in a straight line unless I have feedback control to ensure that the robot moves in a straight line. Instead of using a motor fitted with an encoder to measure distance travelled by each wheel and then feedback to the MCU to adjust accordingly, I thought of trying something new. Using an accelerometer module to measure the distance. This turned out to be extremely challenging. To obtain distance from an accelerometer, you'd have to double integrate and the result is extremely inaccurate. Espcially over time, the error increases exponentially. Check out the accelerometer in action:
![Accelerometer in action](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Motor%20controller%20accelerometer%20test.gif | width = 100) <br> 
Dropped the accelerometer idea and tried using a compass magnetometer module to measure heading. Then orientate the robot accordingly if the robot is off course. Long story short, this turned out to be difficult as well. The compass output x,y,z. With this I know which direction the robot is facing. However, translating this data into PWM commands to supply to motor controller to adjust the heading of the robot proved to be challenging. I wanted to use PID control for this but I couldn't establish a link between the INPUT (magnetometer's x,y,z values) and the OUTPUT (PWM motor values). Ended up scrapping that idea as well. *Cry cry* Pro tip - Best way to measure distance travelled by a robot is to use motors with encoders! I think I've learnt a very good lesson here :) 

The only PCB left to work on was the PCB to distribute the two voltages to their own power rails so that the other PCBs can tap from these rails. Very simple. No complex circuits involved. This didn't take too long to get done.

## So done with the mechanical aspect...
Since I lost access to all those machines in school post graduation, I decided to get Tamiya parts and build the rover with those. Tamiya has a lot of versatile products and its low cost, just what I'm looking for. I also decided to use stronger motors. I bought some machifit gear motors, slightly more expensive than the yellow gear motors, but these machifit motors came with their own mount and nuts & bolts and could be hooked up to almost anything! How nice!  

Since the motor controller was an "overall" success and since I secured all the Tamiya mechanical parts from Japan and new motors from China, It was time to hook everything up. 
![Rover chassis in dev](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20chassis%20in%20dev.jpeg | width = 500)

## A hot mess...
Yes. I know the whole rover sounds like a hot mess (not literally... my PCBs are cool as cucumbers). So here's the block diagram of the rover's electrical system. The big picture: 
![Overall Electrical System Block Diagram]() <br>
The so called "low level controller (LLC)" here acts as a middle man. The low level controller is just an Arduino Mega board. The LLC communicates with the remote control for the rover via Bluetooth and sends the data received from the Bluetooth remote to the motor controller via SPI. In the future, if I add sensors to this rover, the sensors will also interact with the low level controller. The low level controller will process the sensor data and send control signals to the motor controller accordingly. Having the LLC will hopefully allow me to upgrade this rover hassle free in the future!   

The assembly was smooth as butter. The entire electrical system was wired up and "WORKING" on my table. That's what I'm talking about! Robot on a table: 

Last but not least - the firmware for all the MCUs on the rover and the Bluetooth remote. Writing firmware is always fun. Even though I encountered half a million exceptions. I'm kidding. 
## Baby steps
[baby steps](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20baby%20steps.gif | width = 100). 

## Rover gone mad
[Rover gone mad](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20gone%20mad.gif | width = 100) after multiple bugs in the firmware. 

## Rover in action!
[Rover in action](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20in%20action.gif | width = 100)

Oh oh... I totally forgot about the remote control. It was still contained on a breadboard, running off my old Arduino Uno. Quickly made a THT PCB and got it manufactured and soldered. Took about a day to design the PCB in Eagle and 2 weeks for it to be delivered. Soldered it and boom! Done! One good thing that came about from creating so many failed SMD PCBs - now I can whip up simple "WORKING" boards in a few hours... yay!  
![Remote control no case take 1](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Remote%20control%20no%20case%20take%201.jpg | width = 500)
![Remote control no case take 2](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Remote%20control%20no%20case%20take%202.jpg | width = 500)
![Remote control no case with rover](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Remote%20control%20no%20case%20with%20rover.jpg | width = 500)

The remote control needed a case! Luckily I saved some unused 3D printed acrylic mounts from a school project a few years ago. Zip tied the remote control PCB and stuck the 9V battery to the mount.   
![Remote control in case](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Remote%20control%20in%20case.jpg | width = 500)

Stick a fork in it people! We done!
![Rover v1 final take 1](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20v1%20final%20take%201.jpg | width = 100) <br>
![Rover v1 final take 2](https://github.com/devKarthikRaj/Rover-v1/blob/master/Media/Rover%20v1%20final%20take%202.jpg | width = 100) <br>