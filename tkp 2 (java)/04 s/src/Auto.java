public class Auto {
    private String firm;
    private String plateNum; // plate number
    private int maxSpeed;

    public void setFirm(String Firm) {
        firm = Firm;
    }
    public void setPlateNum(String num) { // plate nnumber
        plateNum = num;
    }

    public void setMaxSpeed(int speed) {
        maxSpeed = speed;
    }

    public int getMaxSpeed() {
        return maxSpeed;
    }

    public String getFirm() {
        return firm;
    }

    public String getPlateNum() { // plate nnumber
        return plateNum;
    }

    public Auto() {
        firm = "No name";
        plateNum = "А000АА";
        maxSpeed = 0;
    }

    public Auto(String Firm, String num, int speed) {
        firm = Firm;
        plateNum = num;
        maxSpeed = speed;
    }
}

