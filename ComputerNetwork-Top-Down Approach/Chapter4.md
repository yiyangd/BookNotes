# Network Layer
## 1. Overview of Network Layer
- Transport Segment from sending to receiving host
- On sending side, encapsulates segments into datagrams
- On receiving side, delivers segments to transport layer
- Network Layer Protocols in every host, router
- Router examines header fields in all IP datagrams passing through it

### 1.1 Forwarding and Routing: The Data and Control Planes
- Forwarding: move packets from router's input to appropriate router output
- Routing: determine route taken by packets from source to destination
- Data Plane: 
  * Local, per-router function (Forwarding function)
  * Determines how datagram arriving on router input port is forwarded to router output port
- Control Plane:
  * Network-wide logic
  * Determines 【how datagram is routed】 among routers along end-end path from source host to destination host
  * Two control-plane approaches:
    * Tranditional Routing Algorithms: implemented in routers
      * Individual routing algorithm components in each and every router interact in the control plane
    * Software-defined Networking(SDN): implemented in (remote) servers
      * A distinct (typically remote) controller interacts with local control agents (CAs)
      

### 1.2 Network Service Model:
  - Model defines the `characteristics` of end-to-end delivery of packets between sending and receiving hosts
  - Services for individual datagrams:
    * Guaranteed delivery
    * Guaranteed delivery with bounded delay
  - Services for a flow of datagrams:
    * In-order packet delivery
    * Guaranteed minimum bandwidth to flow
    * Restrictions on changes in inter-packet spacing
  - TODO: 5 models： best effort, CBR, VBR, ABR, UBR
    
  
  
## 2. What's inside a router
- **Figure in notes**
### 2.1 Input Port Processing and Destination-Based Forwarding
- **Figure4.5 in books**
- Input Port Functions:
  * Line termination:
  * Link layer protocol
  * Lookup, forwarding queueing: 
    * Decentralized Switching: 
      * Using header field values, `lookup` output port using forwarding table input port memory (**"match plus action"**)
      * Goal: complete input port processing at "line speed"
      * Queuing: if datagrams arrive faster than forwarding rate into switch fabric
      * destination-based forwarding: forward based `only` on destination IP address (traditional)
      * Generalized forwarding: forward based on `any set of` header field values
- Destination-Based Forwarding Table
  * ranges divide up so nicely
|Destination Address Range|Link interface| 
|---|---|
|00010000-00010111|0|
|00011000-00011000|1|
|00011001-00011111|2|
|otherwise|3|

- Longest Prefix Maching
  * When looking for forwarding table entry for given destination address, use `longest` address prefix that matches destination address.
  * when there are multiple matches, the `router` uses the longest prefix matching rule
|Destination Address Range|Link Interface| 
|---|---|
|00010*** ********|0|
|00011000 ********|1|
|00011*** ********|2|
|otherwise|3|



### 2.2 Switching(notes16)
* Transfer packet from input buffer to appropriate output buffer
* Switching rate: rate at which packets can be transfer from inputs to outputs
  * Often measured as `multiple of input/output` line rate
  * N inputs: switching rate `N times` line rate desirable
* Three types of switching fabrics:

a. Switching via Memory:
* Traditional computers with switching under direct control of CPU
* Packet copied to system's memory
* Speed limited by memory bandwidth

b. Switching via a Bus
* Datagram from input port memory tto output port memory via a shared bus
* `Bus contention`: switching speed limited by bus bandwidth
* 32 Gbps bus, Cisco 5600: sufficient speed for accesss and enterprise routers

c. Switching via an interconnection network
* Overcome bus bandwidtth limitations
* Banyan networks 榕树网络， Crossbar,
### 2.3 Output Port Processing


### 2.5 Packet Scheduling (notes23)
a. FIFO
b. Priority
c. Round Robin
d. WFQ

## 3. The Internet Protocol(IP) (note 28)
- **Figure 4.16 - IPv4 datagram format**
### 3.1 IPv4 Datagram Format
- Version number
- Header length
- Type of Service
- Datagram Length
---
- Identifier, flags, fragmentation offset
- Time-to-live
- Protocol 
- 
### 3.2 IPv4 Datagram Fragmentation and Reassembly
### 3.3 IPv4 Addressing(note 32)
a.  
b.  
c. CIDR  
d. DHCP  

### 3.4 Network Address Translation (NAT) (note 49 - 55)






## 4. Generalized Forwarding and SDN
