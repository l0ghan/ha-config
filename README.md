# My [Home Assistant](https://home-assistant.io) Config

My rule is no cloud based apps, everything must run local, no subscription fees, and the hardware must have Home Assistant integration. I don't want 20 different apps to manage 20 different devices, I don't want my house to become unusable when my internet is offline, and I don't want devices that can be bricked when a manufacturer decides to [turn off their servers](https://www.theguardian.com/technology/2016/apr/05/revolv-devices-bricked-google-nest-smart-home) or [not renew a certificate](https://arstechnica.co.uk/gadgets/2017/11/after-online-outrage-logitech-will-now-replace-harmony-link-devices-for-free/).

My HA installation runs on a Pi 3 with the following:

Software
--------
* [Plex Media Server](https://plex.tv)
* [Homebridge](https://github.com/nfarina/homebridge) *for Apple HomeKit Support*
* [Pi-hole](https://pi-hole.net/) *for network-wide adblocker*
* [PiVPN](http://www.pivpn.io/) *for VPN into my house from anywhere*
* [LetsEncrypt](https://letsencrypt.org/) *for the SSL on my HA domain*

Hardware
--------
* 1 x [Foscam FI8918W](https://www.amazon.co.uk/gp/product/B0046710G6) for a PTZ camera in my toddler's room which I've then configured using HA scripts to allow me to point at three different locations in the room
* 2 x [Foscam FI9800P](https://www.amazon.co.uk/gp/product/B015STDPJ0) - one for the front of the house, one for the back
* 1 x [Foscam C1 Lite](https://www.amazon.co.uk/gp/product/B0196AN3IU) for the landing
* 1 x [Foscam C1](https://www.amazon.co.uk/gp/product/B00T7NX6SY/) for the hallway
* 2 x [Fibaro FGMS-001 Motion Sensor](https://www.amazon.co.uk/gp/product/B00JHHNUPY/) ([manual](http://manuals.fibaro.com/content/manuals/en/FGMS-001/FGMS-001-EN-T-v2.1.pdf)) for motion and temperature (it does brightness too but I'm not making use of that yet)
* 1 x [Aeotec USB Z-Stick S5](https://www.amazon.co.uk/gp/product/B00YETCNOE/ref=oh_aui_detailpage_o06_s00?ie=UTF8&psc=1) plugged into the Pi to interface with the z-wave devices
* [Ikea Tradfri](http://www.ikea.com/gb/en/products/lighting/smart-lighting/) lighting - dimmers and bulbs for the bedroom and dining room.
* 1 x [TP-Link HS110](https://www.amazon.co.uk/HS110-Monitoring-Assistant-Required-UK/dp/B01IBUF48S/)

![UI](/images/home.png)
![UI](/images/rooms.png)
![UI](/images/network.png)

Floorplan
--------
![UI](/images/floorplan.png)

* Dark grey rooms can't be controlled as they have no zwave lights in yet
* Lights in the light grey rooms can be turned on/off
* Yellow rooms are rooms with lights already turned on
* The diagonally hatched rooms are rooms with currently detected motion

Automation
--------
`// todo: document`
