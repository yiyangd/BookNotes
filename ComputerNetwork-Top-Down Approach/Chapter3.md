# Transportation Layer Protocol
## Goals:
* Understand principles behind Transport Layer Services:
    - Multiplexing and Demultiplexing
    - Reliable Data Transfer
    - Flow Control
    - Congestion Control 
* Learn about Internet Transport Layer Protocols:
    - UDP (User Datagram Protocol): 
    - TCP (Transmission Control Protocol): 
    
### 1. Intro and Transport-Layer Services
* Provide logical communication between app processes running on different hosts
* Transport protocols run(implement) in end systems 【but not in network routers】
  * Send side: breaks app messages into segments, passes to network layer
  * Receive side: reassembles segments into messages, passes to app layer
* More than one transport protocol available to apps
  * Internet: TCP and UDP
#### 1.1 Relationship between Transport and Network Layers
* Network-Layer protocol provides logical communication between hosts （IP：Internet Protocol)
* Transport-Layer protocol provides logical communication between processes 【running on different hosts】
* A computer network may make available multiple transport protocols, with each protocol offering a different service model to applications.
> Certain services can be offered by a transport protocol even when the underlying network protocol doesn't offer the corresponding service at the network layer.

#### 1.2 Trans-Layer in the Internet
* Reliable, in-order delivery (TCP)
  * Congestion Control
  * Flow Control
  * Connection Setup
* Unreliable, unordered delivery (UDP)
  * no-frills extension of "best-effort" IP
  * Services not available:
    * Delay guarantees
    * Bandwidth guarantees
### 2. Multiplexing and Demultiplexing 多路传输和多路分离（Services）
a. Multiplexing at sender:
  * Handle data from multiple sockets and add `transport header` 【later used for demultiplexing】 

b. Demultiplexing at receiver:
* Use header information to deliver received segments to correct socket
* Host receives IP datagrams
  * each datagram has source IP address, destination IP address
  * each datagram carries one transport-layer segment
    * each segment has source, destination port number
* Host uses IP address & port numbers to direct segment to appropriate socket

c. Connectionless Demultiplexing:
* Recall:
      
### 3. Connectionless Transport: UDP



### 4. Principles of Reliable Data Transfer
* Important in application, transport, link layers
* Characteristics of unreliable channel will determine the complexity of data transfer protocol (rdt)
*  `ret_send()`: called from above, (e.g. by app.). Passed data to deliver to receiver upper layer
* `udt_send()`: called by rdt, to transfer packet over unreliable
* `deliver_data()`: called by rdt to deliver data to upper
* `rdt_rcv()`: called when packet arrives on rcv-side of channel

#### 4.1 Building a Reliable Data Transfer Protocol
* 

### 5. Connection-Oriented Transport: TCP
#### 5.1 The TCP Connection
* 
#### 5.2

# June, 11 | WEEK 6
### 6. Principles of Congestion Control

### 7. TCP Congestion Control


