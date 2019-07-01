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
  - TODO: 5 models
    
  
  
## 2. What's inside a router
- **Figure in notes**
### 2.1 Input Port Processing and Destination-Based Forwarding
- **Figure4.5 in books**
- Input Port Functions:
  * Line termination:
  * Link layer prottocol
  * Lookup, forwarding queueing: 
    * Decentralized Switching:

### 2.2 Switching
- Switching via Memory
- Switching via a Bus
- Switching via an interconnection network

### 2.3 Output Port Processing


### 2.5 Packet Scheduling (notes23)
a. FIFO
b. Priority
c. Round Robin
d. WFQ

## 3. The Internet Protocol(IP) (note 28)
- **Figure 4.16 IPv4 datagram format**
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
