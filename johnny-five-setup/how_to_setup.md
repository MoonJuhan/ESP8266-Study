# How to use Johnny Five

> I Love You, Johnny~


아두이노에 Johnny Five 사용 방법을 알아보자.

## 방법

1. ESP8266 보드의 개발 환경이 모두 갖춰져 있다고 가정한다.

2. 예제 > Firmata > StandardFirmataWifi를 선택한다.

3. StandardFirmataWifi.ino 파일의 85행 주석을 제거하여 시리얼 모니터에서 디버그 출력을 볼 수 있게 만든다.
```
#define SERIAL_DEBUG
```

4. wifiConfig.h 파일의 119행에 WiFi SSID, 151행에 WiFi Password를 입력한다. 

```
char ssid[] = "Your WiFi SSID";

char wpa_passphrase[] = "Your WiFi Password";
```

4. Firmata 관련 오류가 발생할 경우 아래의 이슈를 확인해봐라.
[https://github.com/adafruit/Adafruit_nRF52_Arduino/issues/602](https://github.com/adafruit/Adafruit_nRF52_Arduino/issues/602)

5. 보드에 업로드 후 시리얼 모니터에 나오는 IP Address를 기억한다.

```
// 대충 이런 식으로 출력 된다.

connected with SON OF ZOLTAR, channel 11
dhcp client start...
ip:10.0.0.49,mask:255.255.255.0,gw:10.0.0.1
IP will be requested from DHCP ...
Attempting to connect to WPA SSID: SON OF ZOLTAR
WiFi setup done
scandone
.SSID: SON OF ZOLTAR
IP Address: 10.0.0.49
signal strength (RSSI): -39 dBm
```

---

 이렇게 하면 Johnny Five 개발 환경 설정이 완료된다.

 위에서 기억한 IP Address를 통하여 Johnny Five 코드를 업로드 할 수 있다.

 아래의 링크에 더 자세한 설명이 작성되어 있다.

## 참고 링크

[How to use an ESP8266 with Johnny-Five](https://boneskull.com/how-to-use-an-esp8266-with-johnny-five/)
