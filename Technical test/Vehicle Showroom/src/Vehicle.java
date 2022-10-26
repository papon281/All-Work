public class Vehicle
{

    private String carType;
    private String model;
    private String engineType;
    private String enginePower;
    private String tyreSize;
    private String turbo;
    private int weight;

    public Vehicle(String carType, String model, String engineType, String enginePower, String tyreSize)
    {
        this.carType = carType;
        this.model = model;
        this.engineType = engineType;
        this.enginePower = enginePower;
        this.tyreSize = tyreSize;

    }

    public Vehicle(String carType, String model, String engineType, String turbo, String enginePower, String tyreSize)
    {
        this.carType = carType;
        this.model = model;
        this.engineType = engineType;
        this.turbo = turbo;
        this.enginePower = enginePower;
        this.tyreSize = tyreSize;

    }

    public Vehicle(String carType, String model, String engineType, String enginePower, String tyreSize, int weight)
    {
        this.carType = carType;
        this.model = model;
        this.engineType = engineType;
        this.enginePower = enginePower;
        this.tyreSize = tyreSize;
        this.weight = weight;
    }

    //getter method
    public String getCarType()
    {
        return this.carType;
    }

    public String getModel()
    {
        return this.model;
    }

    public String getEngineType()
    {
        return this.engineType ;
    }

    public String getEnginePower()
    {
        return this.enginePower;
    }

    public String getTyreSize()
    {
        return this.tyreSize;
    }

    public String getTurbo()
    {
        return this.turbo;
    }

    public int getWeight()
    {
        return this.weight;
    }

    public void setCarType(String carType)
    {
        this.carType = carType;
    }

    public void setModel(String model)
    {
        this.model = model;
    }

    public void setEngineType(String engineType)
    {
        this.engineType = engineType;
    }

    public void setEnginePower(String enginePower)
    {
        this.enginePower = enginePower;
    }

    public void setTyreSize(String tyreSize)
    {
        this.tyreSize = tyreSize;
    }

    public void setTurbo(String turbo)
    {
        this.turbo = turbo;
    }

    public void setWeight(int weight)
    {
        this.weight = weight;
    }

    public void printDetails()
    {
        if(this.carType.equals("Normal Vehicle"))
        {
            System.out.println("Type of vehicle:" + this.carType + " " + this.model + " " + this.engineType + " " + this.enginePower + " "+ this.tyreSize);
        }
        else if(this.carType.equals("Sports Vehicle"))
        {
            System.out.println("Type of vehicle:" + this.carType + " " + this.model + " " + this.engineType + " " + this.enginePower +" " + this.turbo + " "+ this.tyreSize);
        }
        else if(this.carType.equals("Heavy vehicles"))
        {
            System.out.println("Type of vehicle:" + this.carType + " " + this.model + " " + this.engineType + " " + this.enginePower + " "+ this.tyreSize +" " + this.weight);
        }
    }

}
