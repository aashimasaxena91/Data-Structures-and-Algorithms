class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour%12)*30+(double)minutes*0.5;
        double min = minutes*6;
        double angle = abs(h-min);
        if(angle>180) return (360.0-angle);
        return angle;
        
    }
};