#### Team Members:
    David Desrochers
    Addison Garza
    Alexander Martinez
    Samuel Hilfer

# Going Retro - Galactic Intruders
This repository holds a "[Space Invaders](https://www.youtube.com/watch?v=4KuLslq2UvA)" game clone that some teammates and I built using an Arduino UNO system. Between figuring out how to set up our hardware, how we wanted to build our game "cabinet", and actually writing the code, we spent approximately 30 hours over the course of 5 days creating this project. The code is completely our own design (which is obvious if you look at how inefficient it is), and took about 13-15 hours to write alone. We had a lot of fun creating this project for our University class, and we hope that it can help people who want to design something similar create an even better version of our project in the future. A rough video of our final product being tested can be found below:


![GI Gif](https://user-images.githubusercontent.com/63205868/232172141-b16deb92-c489-4f09-a4f0-5dff5850f51b.gif)


### Important Things to Note
The LED "sheet" we used for the project (which can be found in the materials section but is also [linked here](https://www.amazon.com/dp/B075T9RRPM/ref=syn_sd_onsite_mobileweb_40?ie=UTF8&pd_rd_plhdr=t&th=1)) was essentially a strip of lights soldered to look like a sheet. This was probably the most tedious aspect of the project, and it resulted in our code being approx. 800 lines longer than it needed to be due to the various calculations that had to be done for the shooting and win functions.

This is why you see so many if statements, and is what makes our code very inefficient. It's also why our enemies move in a snaking pattern as opposed to progressive one like the classic arcade game, as getting the enemies to move like that with our solution would've required even more tedious calculations, which we ran out of time to do.

Also important, the only way to really lose right now is by shooting your own buildings. Enemies can't kill you, and their movement causes them to "hop" over some of the building's LEDs meaning they cant fully destroy them.

### What Would You Do Differently/if Given More Time?
The only thing we would consider doing differently is 3D printing our arcade "cabinet" instead of building it out of cardboard. This would've given us a cleaner looking final product, and could've given us the opportunity to fix some of the issues we had with this version. Namely, since we didn't own the Arduino-based materials we created this project with, we couldn't securely fasten our breadboard to the cardboard with glue. The reason this was an issue is because the buttons you can see in the video are glued to rolled up tubes of cardboard, and are stuck through the surface of our box where they rest on the actually working buttons connected to our breadboard below. With the breadboard not fastened down, it would often slip, causing the buttons to fall out of the holes they were stuck through. With a 3D printed version we could've easily created a small lip encasing the button breadboard, making so it doesn't slip around.

If we were given more time it would've been relatively easy to get the enemies moving properly, as I said earlier, as well as add some soundfx and music. Besides that, there are some bugs with the game that we wanted to iron out that we didn't get to, like how enemies "respawn" on rare ocasions instead of dying after being shot, or the fact that the enemies cant technically win. The only way you can lose at this point is by destroying your own buildings, as there is no check to see if the enemies have collided with the player, and because of the way the enemies move, they pass over some of the building's lights without ever touching them, meaning they cant fully destroy the buildings.

## List of Materials Needed for this Project

- [Arduino Uno](https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU/ref=sr_1_1_sspa?keywords=Arduino+Uno&qid=1672277687&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExQVM5SVBGT0M4RzM2JmVuY3J5cHRlZElkPUEwMDYzODE2M0c0UEpCRTVBOUpHRCZlbmNyeXB0ZWRBZElkPUEwNDgzODMzMUlIN1I4WVRSM0w1UiZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)

- [LED Sheet (or strip in our case)](https://www.amazon.com/dp/B075T9RRPM/ref=syn_sd_onsite_mobileweb_40?ie=UTF8&pd_rd_plhdr=t&th=1)

- [Wires that work with Arduino Systems (15-20)](https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=asc_df_B01EV70C78/?tag=hyprod-20&linkCode=df0&hvadid=222785939698&hvpos=&hvnetw=g&hvrand=1822016254127035223&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1014434&hvtargid=pla-362913641420&th=1)

- [100k Ohm Resistors (3)](https://www.amazon.com/Resistor-Tolerance-Resistors-Limiting-Certificated/dp/B08QRJZ82J/ref=sr_1_1_sspa?crid=1ZKY5UKDIW2WG&keywords=100k%2Bohm%2Bresistor%2Bfor%2Barduino&qid=1672277810&sprefix=100k%2Bohm%2Bresistor%2Bfor%2Barduino%2Caps%2C114&sr=8-1-spons&smid=A14FP9XIRL6C1F&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExUFk5NzdPVUpSOVhYJmVuY3J5cHRlZElkPUEwMzA4MzI3MVkyVko2R1o0RjlQUyZlbmNyeXB0ZWRBZElkPUEwNTgwNDY1MVY4OFc1VjFBUUxaVCZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU&th=1)

- [Push Buttons/Controls of your Choice](https://www.amazon.com/WOWOONE-12x12x7-3-Tactile-Momentary-Assortment/dp/B08JLWTQ3C/ref=sr_1_5?gclid=CjwKCAiA76-dBhByEiwAA0_s9ReTMsGilkb01fAWmniNBsBtaDdA7c_qhwe9SDdyUjS-pAfPsuP9RhoCj4gQAvD_BwE&hvadid=570507105004&hvdev=c&hvlocphy=1014434&hvnetw=g&hvqmt=e&hvrand=2230252812287056236&hvtargid=kwd-19370621756&hydadcr=18005_13462305&keywords=arduino+buttons&qid=1673465983&sr=8-5)

- ~$40-$50 worth of carboard, markers, hot glue, spraypaint, paper
