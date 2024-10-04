// 1. **Andhra Pradesh**: 49,577,103
// 2. **Arunachal Pradesh**: 1,552,549
// 3. **Assam**: 36,202,369
// 4. **Bihar**: 104,099,452
// 5. **Chhattisgarh**: 25,545,198
// 6. **Goa**: 1,458,545
// 7. **Gujarat**: 63,872,399
// 8. **Haryana**: 28,204,000
// 9. **Himachal Pradesh**: 7,451,955
// 10. **Jharkhand**: 38,802,247
// 11. **Karnataka**: 68,978,900
// 12. **Kerala**: 35,499,575
// 13. **Madhya Pradesh**: 85,358,000
// 14. **Maharashtra**: 125,000,000
// 15. **Manipur**: 3,029,000
// 16. **Meghalaya**: 3,366,000
// 17. **Mizoram**: 1,097,206
// 18. **Nagaland**: 2,189,000
// 19. **Odisha**: 41,974,218
// 20. **Punjab**: 27,743,338
// 21. **Rajasthan**: 81,200,000
// 22. **Sikkim**: 610,577
// 23. **Tamil Nadu**: 77,841,000
// 24. **Telangana**: 39,503,000
// 25. **Tripura**: 4,169,000
// 26. **Uttar Pradesh**: 200,000,000
// 27. **Uttarakhand**: 12,100,000
// 28. **West Bengal**: 91,276,000
#include<bits/stdc++.h>
using namespace std;
map<string,long long> mp;
void declar(){
    mp["West Bengal"] = 91276115;
    mp["Gujarat"] = 60439692;
    mp["Goa"] = 1458545;
    mp["Arunachal Pradesh"] = 1382611;
    mp["Andhra Pradesh"] = 49577103;
    mp["Chhattisgarh"] = 25545198;
    mp["Bihar"] = 104099452;
    mp["Assam"] = 31205576;
    mp["Nagaland"] = 1978502;
    mp["Mizoram"] = 1097206;
    mp["Meghalaya"] = 2966889;
    mp["Manipur"] = 2855794;
    mp["Maharashtra"] = 112374333;
    mp["Madhya Pradesh"] = 72626809;
    mp["Kerala"] = 33406061;
    mp["Karnataka"] = 61095297;
    mp["Jharkhand"] = 32988134;
    mp["Himachal Pradesh"] = 6864602;
    mp["Haryana"] = 25351462;
    mp["Uttarakhand"] = 10086292;
    mp["Uttar Pradesh"] = 199812341;
    mp["Tripura"] = 3673917;
    mp["Telangana"] = 35003674;
    mp["Tamil Nadu"] = 72147030;
    mp["Sikkim"] = 610577;
    mp["Rajasthan"] = 68548490;
    mp["Punjab"] = 27704236;
    mp["Odisha"] = 41974218;
}
int main(){
    declar();
    string s;cout<<"Enter State Name : ";cin>>s;
    cout<<"Population of "<<s<<" is "<<mp[s]<<endl;
}