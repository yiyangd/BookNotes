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
  * Peers are intermittently connected & change IP addresses 
    * Complex Management
  
  
### 1.2 Processes Communicating
* Process: program running on a host

a. Processes running on the same host
* Two processes communicate using `inter-process communication` (defined by OS)

b. Processes in different hosts
* Two processes communicate by `message exchange (using Socket)`
  * Client Process: process that **initiates** communication
  * Server Process: process that waits to be connectted
  
c. Socket: the interface between the process and the computer network
* Processes send & receive messages using Sockets
* Socket analogous to door
  * Sending process sends message out the door
  * Sending process relies on `transport infrastructure` on the other side of the door to deliever message to socket at the receiving process

d. Addressing Processes
* To receive messages, process must have identifier(address)
  * Host-device has unique 32-bit IP address
  * IP address is not enough == since many processes can be running on same host
    * Identifier includes both IP address and **portt numbers** associated with process on host.
    * example port numbers: HTTP server - 80 | mail server - 25
* To send `HTTP message` to gaia.cs.umass.edu web server:
  * IP address: 128.119.245.12
  * port number: 80


### 1.5 Application-Layer Protocols  
* how are messages structured? meanings? when?
* App-layer Protocols defines:
  * The types of messages exchanged, for example, request messages and response messages
  * The syntax of the various message types, such as the fields in the message and how the fields are delineated (刻画，解释）
  * The semantics
  * Rules( When & how ...)
  
* Open Protocols:
  * Defined in RFCs
  * Allows for **interoperability** 互用性
  * Examples: HTTP, SMTP
* Proprietary Protocols: Skype
  
### 1.3 Transport Services Available to Applications
* Data Integrity
  * some apps( file transfer, web transactions, online doc) require 100% reliable data transfer. 
  * some loss acceptable (audio/video)
* Throughput
  * Multimedia apps require minimum amount of throughput to be effective
    * audio: 5kbps-1Mbps
    * video: 10kbps-5Mbps
  * Elastic apps make use of whatever throughput they get 
* Timing
  * some apps( internet telephony, interactive games) require low delay to be effective
* Security


### 1.4 Transport Services Provided by the Internet 
* Trans-layer services tto app-layer for delivery of messages
a. TCP services
* Includes a connection-oriented service and a reliable data transer service
* Flow & Congestion Control

b. UDP services
* no-frills, lightweight transfer prottocol, providing minimal services
* Connectionless
  
|application|application layer protocol|underlying transport protocol|  
|---|---|---|
|email|SMTP[RFC 2821]|3   |  
|  4 |  5 |   6| 
|  7 |  8 |   9|  
## 2.The Web and HTTP (slides17-notes13-34)
### 2.1 Overview of HTTTP 
*
*
* HTTP is stateless 无状态
  * Server maintains no info about past client requests
* Uses TCP:
  * Client initiates TCP connection, port 80
  * Server accepts TCP connection
  * HTTP messages exchange
  * TCP connection close

### 2.2 Non-Persistent and Persistent Connections
a. Non-persistent HTTTP



### 2.3 HTTP Message Format
* Two types:
  * Request:
    - POST:
    - GET:
* `telnet` 远程登录
### 2.4 User-Server Interaction: Cookies
* Many Web sites use cookies

## 3 Electronic Mail in the Internet(notes35-46)
## 4 DNS - The Internet's Directory Service(notes47-60 week2 done)



## 5 Peer-to-Peer Applications (P2P)
## 6. Video Streaming and Content Distribution Networks
### 6.1 Internet Video
### 6.2 HTTP Streaming and DASH
### 6.3 CDN
### 6.4 Netflix
## 7 Socket Programming：Creating Network Applications
