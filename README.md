# Boberto: 2019 IEEE Open Robot Competition

Boberto was a robot developed by six students of LAR-UFRN (https://github.com/lar-ect). The competition consisted in proposing, developing and manufacturing a robot able to solve a portuary challenge.

2019 IEEE Open was a part of LARC (Latin American Robotics Competition) and happened in Rio Grande, RS, Brazil. The robot described here accomplished the second place, but is also currently the double Brazilian champion in the category.

The main goal was deposit as much containers as possible in a enviroment with a simulation of two ships (one blue and other green) and one train (red). Each container had a different pontuation. The team with the greatest score would win the challenge.

Boberto was able to:
1. Identify and advance to a container zone;
2. Choose a container to pick and check its color;
3. If it consisted in a Blue/Green container, grab it and go to the ship zone;
4. If it consisted in a Red container, ignore it and keep moving to the next pile;
5. Come back and do it all over again;

The official document of the competition can be found [here](http://www.cbrobotica.org/wp-content/uploads/OPEN2018_2019_en.pdf).

The students that composed the team of LAR-UFRN were:
* Álvaro Portela (https://github.com/alvaropfn)
* Camila Barbosa (https://github.com/camilabga)
* Gabriel Vantuil (https://github.com/GabrielVantuil)
* Luiz Felipe Santana (https://github.com/LuizFelipeLemon)
* Richardson Santiago (https://github.com/vanluwin)
* Wendell Alves (https://github.com/wendellalves)


## Using [PlatformIO Cli](http://docs.platformio.org/en/latest/)

* Installing

```console
user@computer:~$ sudo python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"
```

* Uploading the code

```console
user@computer:~/IEEE-2019 $ pio run -t upload --upload-port=/dev/ttyUSB0
```

## Arduino Mega Schema

![arduinoMega](./readme_imgs/arduinoMega.png)


## Boberto Pinout

### Stepper motor

| Port      | Pin     |
|:--------: |:-------:|
| Dir       | 52      |
| Step      | 50      |
| Enable    | 13      |

### Bridge H1

| Port      | Pin     |
|:--------: |:-------:|
| Claw_DC 1 | 11      |
| Claw_DC 2 | 12      |
| Motor 2.1 | 9       |
| Motor 2.2 | 10      |


### Bridge H2

| Port         | Pin     |
|:-----------: |:-------:|
| Back Left 2  | 7       |
| Back Left 1  | 8       |
| Back Right 2 | 6       |
| Back Right 1 | 5       |

### Bridge H3

| Port          | Pin     |
|:-------------:|:-------:|
| Front Right 1 | 45      |
| Front Right 2 | 4       |
| Front Left 1  | 46      |
| Front Left 2  | 44      |

### Encoders

| Port       | Pin     |
|:----------:|:-------:|
| Back Left  | 3       |
| Back Right | 2       |
| Front Right| 18      |
| Front Left | 19      |
