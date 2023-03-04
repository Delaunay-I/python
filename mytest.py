import joblib
import numpy as np
import pandas as pd


def simpleFunction(arr):
    X = np.array(arr)
    print("Inside the ML function.")
    print(f"array: {arr}")
    clf = joblib.load("DMD_ML.joblib")
    n_input_feats = clf.named_steps['randomforestclassifier'].n_features_in_
    print(f"number of input features: {n_input_feats}")
    if X.shape[0] != n_input_feats:
        print("number of input variables are not correct!!")
    elif X.shape[0] == n_input_feats:
        print("num inputs match num features!!")

    # prediction = clf.predict(arr)

    return 0