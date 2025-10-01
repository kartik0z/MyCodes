import pandas as pd
import numpy as np

df = pd.read_csv('users.csv')
def clean_data(df):
    """
    Cleans the input DataFrame by handling missing values, removing duplicates,
    and standardizing column names.

    Parameters:
    df (pd.DataFrame): The input DataFrame to be cleaned.

    Returns:
    pd.DataFrame: The cleaned DataFrame.
    """
    
    # Standardize column names to lowercase
    df.columns = [col.lower() for col in df.columns]
    
    # Remove duplicate rows
    df = df.drop_duplicates()
    
    # Handle missing values
    for col in df.select_dtypes(include=[np.number]).columns:
        df[col].fillna(df[col].mean(), inplace=True)
    
    for col in df.select_dtypes(include=[object]).columns:
        df[col].fillna(df[col].mode()[0], inplace=True)
    
    return df

cleaned_df = clean_data(df)
cleaned_df.to_csv('cleaned_users.csv', index=False)
