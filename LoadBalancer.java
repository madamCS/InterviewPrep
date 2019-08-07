/**
 * Implement a load balancer: given a work request, send it to either Machine
 * one or Machine two based on their capacities. 
 */
final class LoadBalancer {

    final Machine one, two;

    public LoadBalancer(Machine one, Machine two) {
        this.one = one;
        this.two = two;
    }

    // Random weighted distribution.
    public Machine route() {
        double weight = (one.capacity) / (one.capacity + two.capacity);
        if (Math.random < weight) {
            return one;
        } else {
            return two;
        }
    }

    public class Machine {
        String name;
        double capacity;
    }
}

// Calling the route function on two machines.
Client {
    final Machine one, two;
    LoadBalancer load = new LoadBalancer(one, two);
    if (/* Request Received*/) {
        load.route();
    }
}