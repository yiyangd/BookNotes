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
  * Deter
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
### 2.1



## 3.
