﻿public class Car extends Auto {
    private String model;
    private int numDoors;
    private Boolean fullTime;

    public Car() {
        super();
        model = "";
        numDoors = 4;
        fullTime = false;
    }

    public Car(String Firm, String num, int speed, String name, int n, Boolean f) {
        super(Firm, num, speed);
        model = name;
        numDoors = n;
        fullTime = f;
    }

    public void setModel(String name) {
        model = name;
    }

    public String getModel() {
        return model;
    }

    public void setNumDoors(int n) {
        numDoors = n;
    }

    public int getNumDoors() {
        return numDoors;
    }

    public void setFullTime(Boolean b) {
        fullTime = b;
    }

    public Boolean isFullTime() {
        return fullTime;
    }

    public String toString() {
        return getFirm() + " " + getPlateNum() + " " + getMaxSpeed() + " " + model + " " + numDoors + " " + fullTime;
    }
}
