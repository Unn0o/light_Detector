# light_Detector
A simple lightdetector made with arduino and php. Made in collabration with <a href="https://github.com/Cefucr">@Cefucr</a>

The password,ssid and address have been removed for obvious reasons :>.

Here is a picture of the arduino:
<img width="200" alt="arudino" src="https://github.com/Cefucr/light_Detector/assets/105347805/ca386e4e-09d5-4fd4-bbda-b8e6d10391d7">

If you cant make sense of something. Here is the version i made with tinkercad. 
In this tinker the board is an Arduino Uno but in the project a Arduino nano 33 IoT was used.

<img width="591" alt="lightdetector arudino" src="https://github.com/Cefucr/light_Detector/assets/105347805/d185161d-7d58-489c-85b2-0e8cbf90eb00">


The server side code takes the values from the arduino and puts them into a file named knowledge.txt.
The code then reads said file and outputs the values onto the webpage.

