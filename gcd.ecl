read int a;
     read int b;
     while a <> b do
         if a > b then
             a := a - b;
         end;
         if b > a then
             b := b - a;
         end;
         if a == b then
             write a;
         end;
     end;