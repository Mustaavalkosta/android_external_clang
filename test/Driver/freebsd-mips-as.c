// Check passing options to the assembler for MIPS targets.
//
// RUN: %clang -target mips-unknown-freebsd -### \
// RUN:   -no-integrated-as -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS32-EB-AS %s
// MIPS32-EB-AS: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
// MIPS32-EB-AS-NOT: "-KPIC"
//
// RUN: %clang -target mips-unknown-freebsd -### \
// RUN:   -no-integrated-as -fPIC -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIC %s
// MIPS32-EB-PIC: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
// MIPS32-EB-PIC: "-KPIC"
//
// RUN: %clang -target mips-unknown-freebsd -### \
// RUN:   -no-integrated-as -fpic -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIC-SMALL %s
// MIPS32-EB-PIC-SMALL: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
// MIPS32-EB-PIC-SMALL: "-KPIC"
//
// RUN: %clang -target mips-unknown-freebsd -### \
// RUN:   -no-integrated-as -fPIE -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIE %s
// MIPS32-EB-PIE: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
// MIPS32-EB-PIE: "-KPIC"
//
// RUN: %clang -target mips-unknown-freebsd -### \
// RUN:   -no-integrated-as -fpie -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIE-SMALL %s
// MIPS32-EB-PIE-SMALL: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
// MIPS32-EB-PIE-SMALL: "-KPIC"
//
// RUN: %clang -target mipsel-unknown-freebsd -### \
// RUN:   -no-integrated-as -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS32-EL-AS %s
// MIPS32-EL-AS: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EL"
//
// RUN: %clang -target mips64-unknown-freebsd -### \
// RUN:   -no-integrated-as -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS64-EB-AS %s
// MIPS64-EB-AS: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EB"
//
// RUN: %clang -target mips64el-unknown-freebsd -### \
// RUN:   -no-integrated-as -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS64-EL-AS %s
// MIPS64-EL-AS: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EL"
//
// RUN: %clang -target mips-unknown-freebsd -mabi=eabi -### \
// RUN:   -no-integrated-as -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS-EABI %s
// MIPS-EABI: as{{(.exe)?}}" "-march" "mips32" "-mabi" "eabi" "-EB"
//
// RUN: %clang -target mips64-unknown-freebsd -mabi=n32 -### \
// RUN:   -no-integrated-as -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS-N32 %s
// MIPS-N32: as{{(.exe)?}}" "-march" "mips64" "-mabi" "n32" "-EB"
//
// RUN: %clang -target mips-linux-freebsd -march=mips32r2 -### \
// RUN:   -no-integrated-as -c %s 2>&1 \
// RUN:   | FileCheck -check-prefix=MIPS-32R2 %s
// MIPS-32R2: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
