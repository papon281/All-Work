import java.util.ArrayList;
import java.util.NoSuchElementException;

public class VehicleArray extends ArrayList
{

    private ArrayList<Vehicle> vehiclesArray;

    public VehicleArray()
    {
        this.vehiclesArray = new ArrayList<>();
    }

    public ArrayList<Vehicle> getVehicles()
    {
        return this.vehiclesArray;
    }

    public int size()
    {
        return this.vehiclesArray.size();
    }

    public void addVehicle(Vehicle element)
    {
        this.vehiclesArray.add(element);
    }

    public void removeVehicle(String carType)
    {
        Vehicle vehicleToRemove = null;
        for (Vehicle v : vehiclesArray)
        {
            if (v.getCarType().equals(carType))
            {
                vehicleToRemove = v;
            }
        }

        if (vehicleToRemove != null)
        {
            vehiclesArray.remove(vehicleToRemove);
        }

        else
        {
            throw new IndexOutOfBoundsException();
        }
    }

    public void printVehicleDetails()
    {
        if (isEmpty())
        {
            System.out.println("Empty..");
        }

        else
        {
            for (Vehicle v : vehiclesArray)
            {
                v.printDetails();
            }
        }
    }

    public void printVehicleWithVisitors()
    {
        if(isEmpty())
        {
            System.out.println("Empty");
        }

        else
        {
            for(Vehicle v : vehiclesArray)
            {
                v.printDetails();
            }
        }
    }

    public boolean isEmpty()
    {
        return vehiclesArray.isEmpty();
    }

}
