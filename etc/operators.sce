//Addition
function result = %py_a_s(x, y)
    result = pyAdd(x, y);
endfunction

%py_a_b = %py_a_s
%py_a_c = %py_a_s
%py_a_py = %py_a_s

%s_a_py = %py_a_s
%b_a_py = %py_a_s
%c_a_py = %py_a_s

//Difference
function result = %py_s_s(x, y)
    result = pyDiff(x, y);
endfunction

%py_s_b = %py_s_s
%py_s_c = %py_s_s
%py_s_py = %py_s_s

%s_s_py = %py_s_s
%b_s_py = %py_s_s
%c_s_py = %py_s_s


//Multiplication
function result = %py_m_s(x, y)
    result = pyMul(x, y);
endfunction

%py_m_b = %py_m_s
%py_m_c = %py_m_s
%py_m_py = %py_m_s

%s_m_py = %py_m_s
%b_m_py = %py_m_s
%c_m_py = %py_m_s

//Division
function result = %py_r_s(x, y)
    result = pyDiv(x, y);
endfunction

%py_r_b = %py_r_s
%py_r_c = %py_r_s
%py_r_py = %py_r_s

%s_r_py = %py_r_s
%b_r_py = %py_r_s
%c_r_py = %py_r_s

//Equals
function result = %py_o_s(x, y)
    result = pyEquals(x, y);
endfunction

%py_o_b = %py_o_s
%py_o_c = %py_o_s
%py_o_py = %py_o_s

%s_o_py = %py_o_s
%b_o_py = %py_o_s
%c_o_py = %py_o_s

//Not Equals
function result = %py_n_s(x, y)
    result = ~pyEquals(x, y);
endfunction

%py_n_b = %py_n_s
%py_n_c = %py_n_s
%py_n_py = %py_n_s

%s_n_py = %py_n_s
%b_n_py = %py_n_s
%c_n_py = %py_n_s

//Greater Than
function result = %py_2_s(x, y)
    result = pyGreater(x, y);
endfunction

%py_2_b = %py_2_s
%py_2_c = %py_2_s
%py_2_py = %py_2_s

%s_2_py = %py_2_s
%b_2_py = %py_2_s
%c_2_py = %py_2_s

//Lesser Than
function result = %py_1_s(x, y)
    result = ~pyGreater(x, y);
endfunction

%py_1_b = %py_1_s
%py_1_c = %py_1_s
%py_1_py = %py_1_s

%s_1_py = %py_1_s
%b_1_py = %py_1_s
%c_1_py = %py_1_s

//Greater Than or Equal To
function result = %py_4_s(x, y)
    result = pyGEquals(x, y);
endfunction

%py_4_b = %py_4_s
%py_4_c = %py_4_s
%py_4_py = %py_4_s

%s_4_py = %py_4_s
%b_4_py = %py_4_s
%c_4_py = %py_4_s

//Lesser Than or Equal To
function result = %py_3_s(x, y)
    result = pyLEquals(x, y);
endfunction

%py_3_b = %py_3_s
%py_3_c = %py_3_s
%py_3_py = %py_3_s

%s_3_py = %py_3_s
%b_3_py = %py_3_s
%c_3_py = %py_3_s