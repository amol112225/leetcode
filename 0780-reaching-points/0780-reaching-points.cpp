class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        while(tx>=sx && ty>=sy){
            if(sx==tx && sy==ty) return true;

            if (tx == sx) return (ty >= sy && (ty - sy) % sx == 0);
            if (ty == sy) return (tx >= sx && (tx - sx) % sy == 0);

            if(tx>ty){
                tx%=ty;
            }
            else if(ty>tx){
                ty%=tx;
            }
            else return false;
        }
       
        return false;
    }
};