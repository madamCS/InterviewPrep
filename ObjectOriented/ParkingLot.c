/** Design a parking lot using OOP.
 */

 public enum vehicleSize{Motorcycle, Compact, Large};

 public abstract class Vehicle {
     ArrayList<ParkingSpot> parkingSpots = new ArrayList<ParkingSpot>;

     String licensePlate;
     int spotsNeeded;
     VehicleSize size;

     public int getSpotsNeeded() {return spotsNeeded;}
     puclic VehicleSize getSize() {return size;}
     
     // Function to park a car in a spot.
     public void parkInSpot(ParkingSpot spot) {
         parkingSpots.add(spot);
     }

     // Remove a car from a spot.
     public void clearSpot(ParkingSpot spot) {
         parkingSpots.remove(spot);
     }

     public boolean canFitInSpot(ParkingSpot spot);
 }

 public class Bus extends Vehicle {
     public Bus() {
         spotsNeeded = spots;
         size = VehicleSize.Large;
     }
 }

 public class Car extends Vehicle {
     public Car() {
         spotsNeeded = 1;
         size = VehicleSize.Compact;
     }
 }
 
 public class Motorcycle extends Vehicle {
     public Motorcycle() {
         spotsNeeded = 1;
         size = VehicleSize.Motorcycle
     }
 }

 public class ParkingSpot {
     private Vehicle vehicle;
     private VehicleSize spotSize;

     public boolean isAvailable() { return vehicle == NULL; }
 }