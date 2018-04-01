# cop290
Creating a package to generate projections of 3D objects and reconstruct them from projections.

while compiling use -std=c++0x flag.


# Input File Formats

Input file for 3D solid:

Points: x_1 y_1 z_1 label_1 , ... , x_n y_n z_n label_n ;

Lines: label_1 label_2 , ... , label_n label_m ;

Normals_of_Projection_planes: n_x n_y n_z , ... , m_x m_y m_z ;


Input file for 2D projection:

Origin: x y z label

Axis1: x y z

Axis2: x y z

Normal: x y z

Points_with_labels: x_1 y_1 z_1 label_11 label_12 ... (space separated set of labels) ; , ... , x_n y_n z_n (set of labels) ; ;

Lines: (space separated set of labels) ; (space separated set of labels) ; , ... , (space separated set of labels) ; (space separated set of labels) ; ;


Reference: https://msdn.microsoft.com/en-us/library/windows/desktop/ms646829(v=vs.85).aspx#open_file