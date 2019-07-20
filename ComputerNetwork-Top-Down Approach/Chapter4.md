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
    
  > The Internet's network layer provides a single service, known as **best-effort** service. With best-effort service, pakckets are neither guaranteed to be received in the order in which they were sent, nor is their eventual delivery even guaranteed. There is no guarantee on the end-to-end delay nor is there a minimal bandwidth guarantee. ( no services)
  
## 2. What's inside a router
- **Figure of generic router architecturein notes**
### 2.1 Input Port Processing and Destination-Based Forwarding
- **Figure4.5 in books**
- Input Port Functions:
  * Line termination:
  * Link layer protocol
  * Lookup, forwarding queueing: 
    * Decentralized Switching: 
      * Using `header field values`, `lookup` output port using forwarding table input port memory (**"match plus action"**)
      * **Goal**: complete input port processing at "line speed"
      * Queuing: if datagrams arrive faster than forwarding rate into switch fabric
      * **destination-based forwarding**: forward based `only` on destination IP address (traditional)
      * **Generalized forwarding**: forward based on `any set of` header field values
- Destination-Based Forwarding Table
  * ranges divide up so nicely
  
|Destination Address Range|Link interface| 
|---|---|
|00010000-00010111|0|
|00011000-00011000|1|
|00011001-00011111|2|
|otherwise|3|

- Longest Prefix Matching (when ranges don't divide up so nicely)
  * When looking for forwarding table entry for given destination address, use `longest` address prefix that matches destination address.
  * when there are multiple matches, the `router` uses the `longest prefix` matching rule

|Destination Address Range|Link Interface| 
|---|---|
|00010*** ******** |0|
|00011000 ******** |1|
|00011*** ******** |2|
|otherwise|3|



### 2.2 Switching(notes16)
* Transfer packet from input buffer to appropriate output buffer
* Switching rate: rate at which   packets can be transfer from inputs to outputs
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
* Overcome bus bandwidth limitations
* Banyan networks 榕树网络， Crossbar, other interconnection nets initially developed to 【connect processors in multiprocessor】
* Advanced Design: Fragmenting datagram into **fixed length cells**, switch cells through the fabric
* Cisco 12000: Switches 60 Gbps through the interconnection network
### 2.3 Output Port Processing
a. Input Port Queueeing
* Fabric slower than input ports combined -> queueing may occur at input queues
  * Queueing delay and loss due to **input buffer overflow**
* Head-of-the-Line(HOL) blocking: queued datagram at front of queue prevents others in queue from moving forward

b. Output Port
* Buffering required when datagrams arrive from fabric faster than the transmission rate.
  * Datagrams(Packets) can be lost due to congestion, lack of buffers
* Scheduling Discipline chooses among queued datagrams for transmission
  * Priority Scheduling - who gets best performance, network neutrality
* buffering when arrival rate via switch exceeds output line speed
* Queueing(delay) and loss due to output ports buffer overflow!


### 2.5 Packet Scheduling (notes23)
* Scheduling: Choose next packet to send on link
a. FIFO: send in order of arrival to queue
* Real-World example: Service Centers
* Discard policy: if packet arrives to full queue: who to discard?
  * Tail drop: drop arriving packet
  * Priority: drop/remove on priority basis
  * Random: drop/remove randomly

b. Priority: Send highest priority queued packet
* Multiple classes, with different priorities
  * Class may depend on marking or other header info
    * e.g. IP source/dest, port numbers, etc
    
c. Round Robin
d. WFQ ( Weighted Fair Queueing)




## 3. The Internet Protocol(IP) (note 28)
- **Figure 4.16 - IPv4 datagram format**
### 3.1 IPv4 Datagram Format
- Version number: IP protocol version number
- Header length: bytes
- Type of Service: "type" of data
- Datagram Length: bytes
---
- 16-bit Identifier, flags, fragmentation offset: for fragmentation/reassembly
- Time-to-live：max number remaining hops (decremented at each router)
- upper layer: upper layer protocol to deliver payload to
- header checksum
- Protocol 
- 
### 3.2 IPv4 Datagram Fragmentation and Reassembly
* Network links have MTU (max.transfer size) - largest possible link-level frame
  * different link types, different MTUs
* Large IP datagram divided(fragmented) within net
  * One datagram becomes several datagrams
  * "Reassembled" only at final destination
  * IP header bits used to identify, order related fragments
* Example

### 3.3 IPv4 Addressing(note 32)
a. Intro

b. Subnets
* IP address:
  * subnet part - high order bits
  * host part - low order bits 
* what's a subnet?
  * device interfaces with same subnet part of IP address
  * can physically reach each other **without intervening router** 
* To determine the subnets, detach each interface from its host or router, creating islands of isolated networks, each of them is called a subnet

c. CIDR: Classless InterDomain Routing
* Subnet portion of address of arbitrary length
* Address format: a.b.c.d/x, where x is # bits in subnet portion of address
* How does a **host** get IP address?
  * Hard-coded by system admin in a file
    * Windows
    * Unix: /etc/rc.config
  * DHCP: dynamically get address from as server - "plug-and-play"
  
d. DHCP：Dynamic Host Configuration Protocol
* Goal: allow host to **dynamically** obtain its IP address from network server when it joins network
  * Can renew its lease on address in use
  * Allows reuse of address (only hold address while connected/"on")
  * Support for mobile users who want to join network (more shortly)
* DHCP overview:
  * Host broadcasts **"DHCP discover** msg [optional]
  * DHCP server responds with **"DHCP offer"** msg [optional]
  * Host requests IP address: **"DHCP request"** msg
  * DHCP server sends address: **"DHCP ack"** msg
* DHCP can return more than just allocated IP address on subnet:
  * address of first-hop router for client
  * name and IP address of DNS server
  * network mask (indicating network versus host portion of address)
* Example
e. Hierarchical Addressing: Route Aggregation  

### 3.4 Network Address Translation (NAT) (note 49 - 55)
* Motivation: local network uses just one IP address as far as outside world is concerned:
  * Range of addresses not needed from ISP
  * Can change address of devices in local network without notifying outside world
  * Can change ISP without changing addresses of devices in local network
  * Devices inside local net not explicitly addressable, visible by outside world
* Implementation: NAT router must:
  * **Outgoing datagrams: replace** (source IP address, port number) of every outgoing datagram to (NAT IP address, new port number) ... remote clients/servers will respond using (NAT IP address, new port number) as destination address
  * **Remember (in NAT translation table)** every (source IP address, port number) to (NAT IP address, new port number) translation pair
  * **Incoming datagrams: replace** (NAT IP address, new port number) in destination fields of every incoming datagram with corresponding (source IP address, port #) stored in NAT table
* 16-bit port-number field:
  * 60000 simultaneous connections with a single LAN-side address
* NAT is controversial: 
  * Routers should only process up to layer 3
  * Address shortage should be solved by IPv6
  * Violates end-to-end argument
    * NAT possibility must be taken into account by app designers
      * e.g. P2P applications
  * NAT traversal: what if client wants to connect to server behind NAT?

### 3.5 IPv6 (note 1-10)
a.
b.



## 4. Generalized Forwarding and SDN (note11 - 19)
* Each router contains a **flow table** that is computed and distributed by a **logically centralized routing controller**
###
