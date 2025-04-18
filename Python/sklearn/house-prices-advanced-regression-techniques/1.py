import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestRegressor
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import GridSearchCV

data=pd.read_csv('./train.csv')
test=pd.read_csv('./test.csv')
all_features=pd.concat([data.iloc[:,1:-1],test.iloc[:,1:]],axis=0)
all_features=pd.get_dummies(all_features,dummy_na=True)
all_features=all_features.fillna(all_features.mean(axis=0))
X=all_features.iloc[:data.shape[0],:]
X_pred=all_features.iloc[data.shape[0]:,:]
y=data.iloc[:,-1]
X=X.to_numpy().astype(float)
y=y.to_numpy().astype(float)
X_pred=X_pred.to_numpy().astype(float)

print("Shapes of datasets:")
print("all_features shape:", all_features.shape)
print("data shape:",data.shape)
print("X shape:", X.shape)
print("y shape:", y.shape)
print("X_pred shape:", X_pred.shape)

scaler = StandardScaler()
X = scaler.fit_transform(X)
X_pred = scaler.transform(X_pred)


param_grid = {
    'n_estimators': [100, 200, 300],
    'max_depth': [None, 10, 20, 30],
    'min_samples_split': [2, 5, 10],
    'min_samples_leaf': [1, 2, 4]
}


model = RandomForestRegressor(random_state=0)
grid_search = GridSearchCV(estimator=model, param_grid=param_grid, cv=5, scoring='neg_root_mean_squared_error', verbose=2, n_jobs=-1)
grid_search.fit(X, y)


print("Best Parameters:", grid_search.best_params_)
print("Best Score:", grid_search.best_score_)


best_model = grid_search.best_estimator_
y_pred = best_model.predict(X_pred)

model.fit(X,y)

y_pred=model.predict(X_pred)
out=pd.DataFrame({'Id':test.iloc[:,0],'SalePrice':y_pred})
out.to_csv('submission.csv', index=False)