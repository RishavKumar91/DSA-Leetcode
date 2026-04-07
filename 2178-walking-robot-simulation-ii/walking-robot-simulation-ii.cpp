class Robot {
public:
vector<vector<int>> v;
int ix = 0 ; 
bool flag = 0;
    Robot(int width, int height) {
        for(int x = 0;x<width ; x++){
            v.push_back({x,0,0});
        }

        for(int y = 1;y<height ; y++){
            v.push_back({width-1,y,1});
        }

        for(int x = width-2;x>=0 ; x--){
            v.push_back({x,height-1,2});
        }

        for(int y = height-2; y>0 ; y--){
            v.push_back({0,y,3});
        }
    }
    
    void step(int num) {
        ix = (ix + num) % v.size();
        flag = 1;
        v[0] = {0,0,3};
    }
    
    vector<int> getPos() {
        return {v[ix][0] , v[ix][1]};
    }
    
    string getDir() {
        if(flag == 0) return "East";
        if(v[ix][2]==0) return "East";
        else if(v[ix][2]==1) return "North";
        else if(v[ix][2]==2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */