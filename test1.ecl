read int n;
     int cp := 2 ;
     while n > 0 do
         int found := 0 ;
         int cf1 := 2 ;
         int cf1s := cf1 * cf1 ;
         while cf1s <= trunc(float(cp)) + trunc(float(0)) do
             int cf2 := 2 ;
             int pr := cf1 * cf2 ;
             while pr <= cp do
                 if pr == cp then
                     found := 1 ;

                     while found < 10 do
                         found := found + 1 ;
                         if found == 3 then
                                found := found - 1 ;
                         end ;
                         while found < 6 do
                             found := found + 1 ;
                             if found == 5 then
                                    found := found - 1 ;
                             end ;
                             found := found + 1 ;
                         end ;
                     end ;

                     found := 1 ;
                 end ;
                 cf2 := cf2 + 1 ;
                 pr := cf1 * cf2 ;
             end ;
             cf1 := cf1 + 1 ;
             cf1s := cf1 * cf1 ;
         end ;
         if found == 0 then
             write cp ;
             n := n - 1 ;
         end ;
         cp := cp + 1 ;
     end ;