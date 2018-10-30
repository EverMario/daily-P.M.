public class MaritalStatus {
    String status;

    MaritalStatus(){
        status = "";
    }

    MaritalStatus(String status){
        this.status = status;
    }

    public void changeStatus(String newSt){
        if(validStatus(newSt)){
            this.status = newSt;
            System.out.println("Status changed successfully!");
        }
        else
            System.out.println("Fail! Invalid status.");
    }

    public boolean validStatus(String newSt){
        if( (status.equalsIgnoreCase("single") && newSt.equalsIgnoreCase("married"))
            || (status.equalsIgnoreCase("married") && ( newSt.equalsIgnoreCase("divorced") || newSt.equalsIgnoreCase("widow") ))
                || (status.equalsIgnoreCase("divorced") && newSt.equalsIgnoreCase("married"))
            || (status.equalsIgnoreCase("widow") && newSt.equalsIgnoreCase("married")) ){
            return true;
        }
        return false;
    }

    public String getStatus()
    {
        return status;
    }
}

