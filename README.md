# IEEE-2019

Boberto da IEEE

[Regras](http://www.cbrobotica.org/wp-content/uploads/OPEN2018_2019_en.pdf)

## Pinout do Boberto

### Motor de Passo

| Port      | Pin     |
|:--------: |:-------:|
| Dir       | 52      |
| Step      | 50      |
| Enable    | 13      |

### Ponte H1

| Port      | Pin     |
|:--------: |:-------:|
| Claw_DC 1 | 11      |
| Claw_DC 2 | 12      |
| Motor 2.1 | 9       |
| Motor 2.2 | 10      |


### Ponte H2

| Port         | Pin     |
|:-----------: |:-------:|
| Back Left 2  | 7       |
| Back Left 1  | 8       |
| Back Right 2 | 6       |
| Back Right 1 | 5       |

### Ponte H3

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

## Utilizando [PlatformIO Cli](http://docs.platformio.org/en/latest/)

* Instalação

```console
user@computer:~$ sudo python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"
```

* Upload de código

```console
user@computer:~/IEEE-2019 $ pio run -t upload --upload-port=/dev/ttyUSB0
```

## Esquemático das coisas

![arduinoMega](./readme_imgs/arduinoMega.png)

![rasp](./readme_imgs/raspberry.jpeg)
