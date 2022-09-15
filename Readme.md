This Project uses a low-cost methodology to convert a traditional AC to a smart AC.


Basic logic:
If human body detection module sense empty room, it return 0 reading to the port.
The program start to do the counting towards 10min / any time that you want, it could be customized.



<br/>


<img src="/AC3.jpg" alt="Alt text" title="Optional title"  height="600" width="800">

<br/>



How my device connect to the AC:
Use the infra RED receptor, connected to the port, and use the controller you have (I did for Gree and Mitsubishi) to take in the array sended by the controllers.
Then store the arrays into database. Send them when the logic designed is met.

Sample signal for Gree:

CLOSE:
Raw: (139) 8956,4408,700,1592,700,500,700,496,700,500,700,1592,700,1592,700,500,700,496,700,1556,740,496,700,476,724,1592,700,496,704,496,700,500,700,496,700,500,700,500,700,496,676,524,700,496,704,1588,704,496,676,524,700,1592,700,500,700,496,700,500,700,1592,700,500,700,1592,700,496,700,500,700,1592,700,500,700,19856,700,496,704,496,700,496,704,476,720,500,700,496,704,496,700,500,700,496,700,476,724,496,704,496,700,496,704,1564,728,496,704,496,700,496,700,500,704,496,700,496,704,496,700,500,700,496,700,500,700,496,704,496,704,496,700,496,700,1592,704,1592,700,1592,700,496,704,



<br/>

<img src="/smartAC.jpg" alt="Alt text" title="Optional title" height="500" width="800">


<br/>



For Mitsubishi:
open:
Raw: (583) 3428,1700,440,1252,448,1252,448,412,448,416,444,416,448,1252,444,416,448,412,452,1252,444,1252,448,416,444,1252,448,412,452,412,448,1252,448,1252,444,416,448,1252,444,1252,448,416,448,416,444,1252,444,420,444,412,452,1252,444,416,448,416,444,416,448,416,448,416,444,416,448,416,444,416,448,416,444,416,448,416,444,416,448,416,448,412,520,344,448,416,444,416,448,416,444,416,524,340,448,1248,448,416,448,412,448,416,444,416,448,416,448,1248,448,1256,444,412,452,1252,444,392,472,1252,444,1252,448,416,520,1180,444,416,444,416,448,416,448,412,448,416,448,1252,444,1252,448,416,444,1252,448,1248,448,416,448,412,452,1248,448,1252,448,412,448,416,448,1248,448,412,452,1252,444,392,472,416,448,412,448,416,448,416,444,416,448,416,444,416,448,416,448,412,448,416,448,412,448,416,448,412,448,416,448,416,444,416,520,344,444,416,452,412,448,416,444,416,448,376,484,416,448,416,444,416,448,416,448,412,448,416,448,412,448,416,448,412,448,416,448,416,444,420,444,412,448,416,448,1248,448,420,444,416,448,412,448,416,448,416,444,420,444,416,444,420,444,416,448,412,448,416,448,412,448,416,448,412,448,416,448,416,448,412,448,412,452,412,448,1252,444,420,444,392,472,416,444,1252,448,1252,444,416,448,416,448,15752,3476,1644,448,1248,448,1252,448,416,444,416,448,412,452,1248,448,412,448,416,448,1252,448,1248,448,416,448,1248,520,344,448,416,444,1256,444,1252,448,412,448,1252,448,1248,448,380,484,412,452,1248,448,416,448,416,444,1252,448,408,452,416,448,412,448,412,452,416,500,364,444,412,504,336,472,412,452,412,504,360,504,360,496,364,448,416,500,360,500,364,448,416,444,416,500,360,500,364,504,1192,448,416,500,360,448,412,504,364,444,416,500,1200,448,1248,448,416,448,1252,444,416,448,1248,448,1252,448,412,452,1248,448,416,500,360,448,416,500,360,500,364,500,1200,500,1196,448,412,452,1248,500,1200,448,412,448,416,500,1196,452,1176,576,356,504,360,504,1156,488,412,504,1196,500,364,500,360,500,360,504,360,500,360,500,364,500,360,504,360,500,364,496,364,500,360,500,364,504,360,500,364,496,364,500,364,496,280,672,248,524,364,500,360,500,364,500,364,500,360,504,360,496,364,500,364,496,368,496,364,500,364,496,344,520,364,496,364,500,364,496,368,472,388,472,392,472,392,492,1204,496,340,524,364,472,388,496,368,496,368,472,388,496,368,472,388,472,368,496,388,476,384,476,388,476,388,472,388,476,388,472,388,476,388,472,388,476,388,472,1228,472,388,476,388,472,388,476,1224,472,1228,472,388,472,392,472




No need to mention, this is a huge array.





At first i store them in the main memory of arduino uno, but they are really too big. So i use const int to store them to flash memory, which is enough for more than 50 lines for Gree. But some good companies in AC developer more complex infrared red signal, taking more space in my memory. Maybe could use Wifi module to store them in the online databse such as Mongodb, so that the device can pull those data when necessary. Plus, connecting to the wifi allows remote start, set timer, and more advanced features. Which is a to-do for this project.


<br/>

<img src="/smartAC2.jpg" alt="Alt text" title="Optional title" height="600" width="800">

<br/>


I designed 2 gen of outshell. Both 3D printable.


<br/>

<img src="/mdoels.jpg" alt="Alt text" title="Optional title" height="600" width="800">

<img src="/modelsFor2Gen.jpg" alt="Alt text" title="Optional title" height="600" width="800">

<br/>

** Abstract **

With the development of the intelligent home, many smart homes that are convenient for people's life are gradually stepping into people's lives. The so-called smart home refers to the integration of facilities related to home life by using generic cabling technology, network communication technology, security protection technology, automatic control technology, and audio and video technology to build an efficient management system of residential facilities and family schedule, improve the safety, convenience, comfort, and artistry of home, and achieve an environment-friendly and energy-saving living environment. Suppose the air conditioner can be made intelligent, for example. In that case, it will automatically turn off half an hour after people leave the air-conditioned room. They no longer worry about forgetting to turn off the air conditioner when they are in a hurry to go to work or in public places such as classrooms, and people lack the awareness of saving electricity. Therefore, I want to develop an intelligent air conditioning control system to facilitate user operation and save energy, environmental protection, and money.


1 Infrared module
One part is to use an infrared transmitter and receiver, which can easily make the air conditioner reach the effect of temperature regulation and switch. The other part uses HC-SR501. HC-SR501 is a human body infrared sensing module that can sense the presence of people within the range. When someone is in the air-conditioned room, the air conditioner can continue to operate. As long as people leave the room for a particular time, they can send a shutdown signal through the front infrared transmitter to shut down the air conditioner to save power.
2 Temperature module
DHT11 was used in this experiment for its advantages in many aspects. DHT11 has an ultra-small volume, low power consumption, fast response speed, and accurate temperature measurement and humidity. The temperature and humidity information can be directly transferred to Arduino to perform the next step.

3 System Installation

3.1 Program Construction
Because Arduino is used as the microcontroller, Arduino IDE is used as the programming software in this experiment.

① Air conditioning infrared code
The circuit connected with the infrared receiver and Arduino is used to receive the infrared signals of opening, closing, and temperature regulating on the remote controller of the air conditioner. The 229 lengths of array infrared signal read are programmed to facilitate proper control of the air conditioner in the future.





@copyright Anthony Chen






