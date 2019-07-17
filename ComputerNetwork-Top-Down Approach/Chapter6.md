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
  * Ethernet card, 802.11 card; Ethernet chipset
  * implements link, physical layer
* Attaches into host's system buses
* Combination of hardware, software, firmware
* **Adaptors Communicating**:
  * Sending side:
    > The Controller takes a datagram from host memory and encapsulates it in a link-layer frame (filling in the frame's various fields lke error checking bits, rdt, flow control, etc), and then transmits the frame into the communication link, following the link-access protocol. 
  * Receiving side:
    > A controller receives the entire frame, and extracts the network-layer datagram. If the link-layer performs error detection, then it is the sending controller that sets the error-detection bits in the frame header and it is the receiving controller that performs error detection.
### 2. Error-Detection and Correction Techniques
* EDC = Error Detection and Correction bits (redundancy)
* D = Data protected by error checking, may include header fields
* Error detection not 100% reliable!
  * Protocol may miss some errors, but rarely
  * Larger EDC field yields better detection and correction
#### 2.1 Parity Checks
### 3. Multiple access protocols 

### 4. LANs(Local Area Networks)


### 5. Link Virtualization: MPLS
### 6. Data Center Networking
