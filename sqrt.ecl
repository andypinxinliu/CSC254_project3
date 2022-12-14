read real d;
real l := d / 2.0;
while l * l > d do
    l := l / 2.0;
end;
real h := 2.0 * l;
real err := d - (l * l);
if err < 0.0 then err := 0.0 - err; end;
while err > 1.e-10 do
    real a := (l + h) / 2.0;
    if (a * a) < d then l := a; end;
    if (a * a) > d then h := a; end;
    err := d - (l * l);
    if err < 0.0 then err := 0.0 - err; end;
end;
write l;