class ParkingSystem {
public:
    ParkingSystem(int b, int m, int s) {
        big = b;
        medium = m;
        small = s;
    }
    
    bool addCar(int cartType) {
        if(cartType == 1){
            if(big > 0){
                big--;
                return true;
            }
            return false;
        }
        if(cartType == 2){
            if(medium > 0){
                medium--;
                return true;
            }
            return false;
        }
        if(cartType == 3){
            if(small > 0){
                small--;
                return true;
            }
            return false;
        }
        return false;
    }

private:
    int big, medium, small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */