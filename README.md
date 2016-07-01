# SherpaShare-Dash-Link
A project build on Arduino to connect with an Android device via Bluetooth

Background
SherpaShare wants a simple hardware workers can carry with them to track their work with their
smart phone. The hardware should be small, light, easy to attach to some surface, long battery life
and stable connection to the smartphone.
Use Case
Uber Driver Bob puts the SherpaShare Dash Link on his car, pair with SherpaShare mobile app.
When Bob picks up a customer, he clicks the button to start to track the ride. After he drops off the
pax, he clicks the button again to end the tracking. When he leaves the car, the link will disconnect
with the smart phone. When he goes back into the car, the link shall auto connect with the phone
and indicates it is connect (phone beep or device beeps).
Doordash Deliverer John carries the SherpaShare Dash Link with his car key. When he got the
order from Doordash and hit the road, he clicks the button to track his work. After he delivered the
food, he will click the button to stop the tracking.
Spec
The dash link shall be small ( similar size like the amazon dash button or even smaller: width
10MM, length 30MM, thinness 10MM). It shall have one giant button to handle all the connection
and actions. There shall be two lights, one is to indicate whether the link still function (has battery).
The other lights to indicate the status of the device or flow. The device shall also has a speaker
with different sounds for different state of the device. The device supports pairing with smartphone
via BlueTooth. The device shall has built­in battery to support long life (or large number of usage).
The device shall have two lights. One light for tracking and the other for pairing. When it's tracking
the light is green, when it's not tracking the light is turned off. Long press to pair, and the light will
flash blue. If the battery is low, when it's tracking, instead of green, it can be yellow/red indicating
battery is low. Every time you get in the car, if it automatically repairs, the light should also blink
blue. The device has different sound for pairing, turn on, and turn off, if battery is low, when it
turns on, it can also say something like 'battery low'.
Device States:
1. Shutdown
2. Standby
3. Pairing
4. Paired
5. Tracking ON
6. Tracking OFF
Here is the basic state machine I am thinking, it might not be comprehensive.
Consideration
The device shall be very intuitive to use. It shall have long life and very stable connection quality.
The button shall be easy to press.
Things need to evaluate:
1. Whether the battery shall be replaceable (if not, how long it can last, how expense to
make)
2. Whether the One button or Two button (one is ON, the other is OFF)?
