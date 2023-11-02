import tkinter as tk

# Function to update the entry field with clicked number or operator
def update_entry(value):
    current_text = entry.get()
    if current_text == "0" or current_text == "Error":
        entry.delete(0, tk.END)
    entry.insert(tk.END, value)

# Function to perform mathematical operations
def calculate():
    try:
        expression = entry.get()
        result = eval(expression)
        entry.delete(0, tk.END)
        entry.insert(tk.END, result)
    except Exception:
        entry.delete(0, tk.END)
        entry.insert(tk.END, "Error")

# Create a tkinter window
root = tk.Tk()
root.title("Calculator")
root.geometry("300x400")
root.configure(bg="pink")

# Entry field
entry = tk.Entry(root, font=('Arial', 18), justify="right")
entry.insert(0, "0")
entry.grid(row=0, column=0, columnspan=4, padx=10, pady=10, ipadx=10, ipady=10)

# Numeric buttons
buttons = [
    "7", "8", "9", "/",
    "4", "5", "6", "*",
    "1", "2", "3", "-",
    "0", ".", "=", "+"
]

row_val = 1
col_val = 0

for button in buttons:
    if button == "=":
        tk.Button(root, text=button, padx=20, pady=20, bg="red", fg="white", font=('Arial', 18), command=calculate).grid(row=row_val, column=col_val)
    else:
        tk.Button(root, text=button, padx=20, pady=20, bg="red", fg="white", font=('Arial', 18), command=lambda b=button: update_entry(b)).grid(row=row_val, column=col_val)
    col_val += 1
    if col_val > 3:
        col_val = 0
        row_val += 1

root.mainloop()
