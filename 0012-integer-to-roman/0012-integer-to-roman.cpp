class Solution {
public:
    string intToRoman(int num) {
        string rom="";
        while(num>0){
            if(num>=1000) rom+="M", num-=1000;
            else if(num>=900) rom+="CM", num-=900;
            else if(num>=500) rom+="D", num-=500;
            else if(num>=400) rom+="CD", num-=400;
            else if(num>=100) rom+="C", num-=100;
            else if(num>=90) rom+="XC", num-=90;
            else if(num>=50) rom+="L", num-=50;
            else if(num>=40) rom+="XL", num-=40;
            else if(num>=10) rom+="X", num-=10;
            else if(num>=9) rom+="IX", num-=9;
            else if(num>=5) rom+="V", num-=5;
            else if(num>=4) rom+="IV", num-=4;
            else rom+="I", num-=1;
        }
        return rom;
    }
};