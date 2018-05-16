#ifndef PLOTTER_H
#define PLOTTER_H

void plot(double xMin, double xMax, std::string funcName, QCustomPlot *sheet);

typedef std::vector<double> (*f)(std::vector<double>);
std::map<std::string, f> plot_functions {{"1/x",  &div_func   },
                                         {"x^2",  &square_func},
                                         {"sqrt", &square_root},
                                         {"sin",  &sin_func   },
                                         {"cos",  &cos_func   },
                                         {"tan",  &tg_func    },
                                         {"sinh", &sinh_func  },
                                         {"cosh", &cosh_func  },
                                         {"tanh", &tgh_func   },
                                         {"exp",  &exp_func   },
                                         {"ln",   &ln_func    }};

#endif // PLOTTER_H
