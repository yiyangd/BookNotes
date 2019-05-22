## Goals:
* Conceptual, implementation aspects of network application protocols
  * transport-layer service models
  * client-server paradigm
  * peer-to-peer paradigm
* Learn about protocols by `examining` popular application-level protocols
  * HTTP | FTP | SMTP/POP3/IMAP | DNS
* Creating network applications
  * Socket API
## 1. Principles of Network Applications(slides1-16,notes1-12)
* Some Network Apps: e-mail, web, text messaging, remote login, P2P file sharing...
* Write Programs that:
  * Run on (different) end systems
  * Communicate over network
  * eg. web `server` software communicates with `browser` software
* no need to write software for `network-core devices`
  * network-core devices do not run user applications
  * applications on end systems allows for rapid app development, propagation
### 1.1 Network Application Architectures
a. client-server architecture:
* Server: 
  * Always-on host
  * Permanent IP address
  * Data centers for scaling
* Clients:
  * Communicate with Server
  * May be intermittently(间断地）connected
  * do not communicate directly with each other
b. P2P architecture:
  * no always-on server
  * **arbitrary** end systems directly communicate
  * Peers request service from other peers & provide service in return to other peers
    * **Self Scalability**: New peers bring new service capacity as well as new service demands
  * Peers are intermitteently connected & change IP addresses 
    * Complex Management
  
  
### 1.2 Processes Communicating


### 1.5 Application-Layer Protocols
|application|application layer protocol|underlying transport protocol|  
|---|---|---|
|email|SMTP[RFC 2821]|3   |  
|  4 |  5 |   6| 
|  7 |  8 |   9|  
## 2.The Web and HTTP (slides17-notes13-34)
### 2.2 Non-Persisteent and Persistent Connections
### 2.3 HTTP Message Format
* Two types:
  * Request:
    - POST:
    - GET:
* `telnet` 远程登录
### 2.2.4 User-Server Interaction: Cookies
* Many Web sites use cookies

## 2.3 Electronic Mail in the Internet(notes35-46)
## 2.4 DNS - The Internet's Directory Service(notes47-60 week2 done)



## 2.5 Peer-to-Peer Applications (P2P)
## 6. Video Streaming and Content Distribution Networks
### 6.1 Internet Video
### 6.2 HTTP Streaming and DASH
### 6.3 CDN
### 6.4 Netflix
## 2.7 Socket Programming：Creating Network Applications
