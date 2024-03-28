CREATE DATABASE POOProjBD
ON PRIMARY
(
Name = File1,
FileName = 'C:\Users\George\Desktop\Proiect POO\OPP-Project\BD\POOProjBD.mdf',
size = 10MB, -- KB, Mb, GB, TB
maxsize = unlimited,
filegrowth = 1GB
),
(
Name = File2,
FileName = 'C:\Users\George\Desktop\Proiect POO\OPP-Project\BD\POOProjBD.ndf',
size = 10MB, -- KB, Mb, GB, TB
maxsize = unlimited,
filegrowth = 1GB
)
LOG ON
(
Name = Logger,
FileName = 'C:\Users\George\Desktop\Proiect POO\OPP-Project\BD\POOProjBDLogg.ldf',
size = 10MB, -- KB, Mb, GB, TB
maxsize = unlimited,
filegrowth = 1024MB
)