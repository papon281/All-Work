import java.util.InputMismatchException;
import java.util.Scanner;

public class VehicleMenu
{

    Scanner console = new Scanner(System.in);
    private final VehicleArray vehiclesList = new VehicleArray();
    private boolean choice = true;

    public void showMenu()
    {

        while (choice)
        {
            try
            {
                System.out.println("1: Add vehicle in the showroom.\n2: Remove vehicle from th showroom.\n3: Print vehicle details.\n4: Print vehicle details with current expected visitors.\n5: Exit");
                int menu = Integer.parseInt(console.nextLine());
                switch (menu)
                {
                case 1:
                    addVehicle();
                    break;
                case 2:
                    removeVehicle();
                    break;
                case 3:
                    vehiclesDetails();
                    break;
                case 4:
                    vehicleListWithTotalVisitors();
                    break;
                case 5:
                    System.exit(0);
                    break;
                }
            }
            catch (InputMismatchException e)
            {

                System.out.println("\n" + e + " \nhas happened, choose value from 1 o 5.\n Click enter to continue...");

            }
        }
    }

    private void addVehicle()
    {
        String carType, model, engineType, enginePower,tyreSize,turbo;
        int weight;
        try
        {

            System.out.println("Enter the car type:");
            carType = console.nextLine();
            System.out.println("What was your car model?");
            model = console.nextLine();
            System.out.println("What's the EngineType of your vehicle?");
            engineType = console.nextLine();
            validateEngine(carType,engineType);
            System.out.println("What's the engine power of your Vehicle?");
            enginePower = console.nextLine();
            System.out.println("What's the tyre size of your Vehicle?");
            tyreSize = console.nextLine();

            if(carType.equals("Normal vehicle"))
            {
                Vehicle vehicle = new Vehicle(carType, model, engineType, enginePower, tyreSize);
                vehiclesList.addVehicle(vehicle);
            }

            else if(carType.equals("Sports vehicle"))
            {
                System.out.println("Is you need turbo power in your vehicle?");
                turbo = console.nextLine();
                Vehicle vehicle = new Vehicle(carType, model, engineType, turbo, enginePower, tyreSize);
                vehiclesList.addVehicle(vehicle);
            }

            else if(carType.equals("Heavy vehicle"))
            {
                System.out.println("Whats's the weight of your vehicle?");
                weight = Integer.parseInt(console.nextLine());
                Vehicle vehicle = new Vehicle(carType, model, engineType, enginePower, tyreSize, weight);
                vehiclesList.addVehicle(vehicle);
            }

        }
        catch (InputMismatchException e)
        {
            console.nextLine();
            System.out.println("\nMismatch" + " has happened, make sure to input correct values.\n Click enter to continue...");
        }
    }

    private void removeVehicle()
    {
        if (vehiclesList.isEmpty())
        {

            System.out.println("There are no vehicles in the list");
        }

        else
        {
            try
            {
                System.out.println("Type car type you want to remove: ");
                String car_type = console.nextLine();
                vehiclesList.removeVehicle(car_type);
                System.out.println(car_type + " has been removed.\n");

            }

            catch (IndexOutOfBoundsException e)
            {

                System.out.println("\n" + e + "\nhas happened, you have to pick Vehicle that EXISTS.\n Click enter to continue...");

            }

            catch (InputMismatchException e)
            {

                System.out.println("\n" + e + "\nhas happened, input an string.\n Click enter to continue...");

            }
        }
    }

    private void vehiclesDetails()
    {

        System.out.println("List of vehicles: ");
        printVehicleDetails();

    }

    private void printVehicleDetails()
    {
        if (vehiclesList.isEmpty())
        {
            System.out.println("Empty..");
        }
        else
        {
            for(Vehicle v : vehiclesList.getVehicles())
            {
                if(v.getCarType().equals("Normal vehicle"))
                {
                    System.out.println(v.getCarType() +" " + v.getModel() +" " +v.getEngineType() + " " + v.getEnginePower() +" " + v.getTyreSize());
                }
                else if(v.getCarType().equals("Sports vehicle"))
                {
                    System.out.println(v.getCarType() +" " + v.getModel() +" " +v.getEngineType() + " " + v.getTurbo() +" " +v.getEnginePower() +" " + v.getTyreSize());
                }

                else if(v.getCarType().equals("Heavy vehicle"))
                {
                    System.out.println(v.getCarType() +" " + v.getModel() +" " + v.getEngineType() + " " + v.getEnginePower() +" " + v.getTyreSize() + " " + v.getWeight());
                }
            }
        }

    }

    private void printVehicleDetailsWithVisitors()
    {
        int visitors = 30;
        if (vehiclesList.isEmpty())
        {
            System.out.println("Empty..");
            System.out.println("Total expected visitors: " + visitors);
        }
        else
        {
            for(Vehicle v : vehiclesList.getVehicles())
            {
                if(v.getCarType().equals("Normal vehicle"))
                {
                    System.out.println(v.getCarType() +" " + v.getModel() +" " +v.getEngineType() + " " + v.getEnginePower() +" " + v.getTyreSize());
                    System.out.println("Total expected visitors: " + visitors);
                }
                else if(v.getCarType().equals("Sports vehicle"))
                {
                	visitors = visitors + 20;
                    System.out.println(v.getCarType() +" " + v.getModel() +" " +v.getEngineType() + " " + v.getTurbo() +" " +v.getEnginePower() +" " + v.getTyreSize());
                    System.out.println("Total expected visitors: " + visitors);
                }

                else if(v.getCarType().equals("Heavy vehicle"))
                {
                    System.out.println(v.getCarType() +" " + v.getModel() +" " + v.getEngineType() + " " + v.getEnginePower() +" " + v.getTyreSize() + " " + v.getWeight());
                    System.out.println("Total expected visitors: " + visitors);
                }
            }
        }

    }

    private void vehicleListWithTotalVisitors()
    {
        printVehicleDetailsWithVisitors();
    }

    private void validateEngine(String car, String engine)
    {
        if((car.equals("Sports vehicle")) && (!engine.equals("Oil")))
        {
            throw new InputMismatchException("\nEngine type should be oil only\n");
        }

        else if((car.equals("Heavy vehicle")) && (!engine.equals("Diesel")))
        {
            throw new InputMismatchException("\nEngine type should be diesel only\n");
        }
    }
}
