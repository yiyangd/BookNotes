### 1. Intro to
* nodes:
* links:
* Link Layer (Layer-2) packet: **Frame**, encapsulates datagram
> Data-link layer has responsibility of transferring datagram from one node to physically adjacent node over a link
* Datagram transferred by different link protocols over different links
  * Each link protocol provides different services
#### 1.1 The Services Provided by the Link Layer
* Framing & Link Access: 
  * Encapsulate datagram into frame, adding header, trailer
  * Channel access if shared medium
  * "MAC" addresses used in frame headers to identify source, destination
    * Different from IP address!
* Reliable Delivery:
  * Recall: transport-layer protocol like TCP also provide a reliable delivery service.
  * Seldom used on low bit-error link (fiber, some twisted pair) ==> therefore many wired link-layer protocols do not provide a reliable delivery service
  * Wireless links: high error rates
* Flow Control:
  * Pacing between adjacent sending and receiving nodes
* Error Detection:
  * Errors caused by signal attenuation and electromagnetic noise
  * Receiver detects presence of errors:
    * Signals sender for retransmission or drops frame
* Error Correction:
  * Receiver identifies **and corrects** bit error(s) without resorting to retransmission
* Half-duplex and full-duplex
  * With half duplex, nodes at both ends of link can transmit, but not at same time

#### 1.2 Where is the Link Layer Implemented?
* In each and every host
* Link Layer implemented in "adaptor" (**network interface card:NIC**) or on a chip
  * Ethernet card

* **Adaptors Communicating:
  * Sending side:

* Receiving side:
### 2. Error-Detection and Correction Techniques
### 3. Multiple access protocols 
### 4. LANs(Local Area Networks)


### 5. Link Virtualization: MPLS
### 6. Data Center Networking
