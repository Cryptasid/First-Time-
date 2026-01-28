import json
import os
import tkinter as tk
from tkinter import ttk, messagebox, scrolledtext


DATA_FILE = "firefighters.json"
EXPERTISE_OPTIONS = [
    "Rescuer",
    "Medic",
    "Electric Technician",
    "Chemical Technician"
]

# Theme colors
BG = "#0f0f10"
PANEL = "#151515"
ACCENT = "#c0392b"
ACCENT_DARK = "#8e2a22"
TEXT = "#ffffff"
SUBTEXT = "#d1d1d1"
BTN_HOVER_MULT = 1.08

# Utilities

def safe_load_json(path):
    if not os.path.exists(path):
        return []
    try:
        with open(path, "r", encoding="utf-8") as f:
            return json.load(f)
    except Exception:
        return []

def safe_save_json(path, data):
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2, ensure_ascii=False)

def hex_to_rgb(hex_color):
    c = hex_color.lstrip("#")
    return tuple(int(c[i:i+2], 16) for i in (0, 2, 4))

def rgb_to_hex(rgb):
    return "#{:02x}{:02x}{:02x}".format(*rgb)

def lighten(hex_color, mult=1.12):
    r, g, b = hex_to_rgb(hex_color)
    lighter = tuple(min(255, int(c * mult)) for c in (r, g, b))
    return rgb_to_hex(lighter)

# Data handler

class FireStationTracker:
    def __init__(self, file_name=DATA_FILE):
        self.file_name = file_name
        self.crew = []
        self.load_crew()

    def load_crew(self):
        self.crew = safe_load_json(self.file_name)

    def save_crew(self):
        safe_save_json(self.file_name, self.crew)

    def add_firefighter(self, ff_dict):
        self.crew.append(ff_dict)
        self.save_crew()

    def update_firefighter(self, index, ff_dict):
        self.crew[index] = ff_dict
        self.save_crew()

    def delete_firefighter(self, index):
        del self.crew[index]
        self.save_crew()

class FireStationApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Fire Station Command — Crew Manager")
        self.geometry("980x680")
        self.minsize(900, 600)
        self.configure(bg=BG)
        self.iconbitmap("firefighter.ico")
        self.tracker = FireStationTracker()
        self.status_var = tk.StringVar(value="Ready")
        self.setup_style()
        self.build_ui()

    def set_app_icon(self, icon_path="firefighter.ico"):
        try:
            icon = tk.PhotoImage(file=icon_path)
            self.iconphoto(False, icon)
        except Exception as e:
            print("Icon load failed:", e)
    def setup_style(self):
        style = ttk.Style(self)
        try:
            style.theme_use("clam")
        except Exception:
            pass
        style.configure("Main.TFrame", background=BG)
        style.configure("Panel.TFrame", background=PANEL, relief="flat")
        style.configure("Header.TLabel", background=BG, foreground=ACCENT, font=("Segoe UI", 20, "bold"))
        style.configure("SubHeader.TLabel", background=PANEL, foreground=SUBTEXT, font=("Segoe UI", 10))
        style.configure("TButton",
                        background=ACCENT,
                        foreground=TEXT,
                        font=("Segoe UI", 11, "bold"),
                        padding=8,
                        relief="flat")
        style.map("TButton",
                  background=[("active", lighten(ACCENT, 1.0)), ("disabled", "#6b6b6b")])

        style.configure("Treeview",
                        background=PANEL,
                        fieldbackground=PANEL,
                        foreground=TEXT,
                        rowheight=28,
                        font=("Segoe UI", 10))
        style.configure("Treeview.Heading", font=("Segoe UI", 11, "bold"), background="#111111", foreground=SUBTEXT)
        style.map("Treeview", background=[("selected", ACCENT_DARK)])

    #  UI
    def build_ui(self):
        top_frame = ttk.Frame(self, style="Main.TFrame")
        top_frame.pack(fill="both", expand=True, padx=18, pady=18)


        hdr_frame = ttk.Frame(top_frame, style="Main.TFrame")
        hdr_frame.pack(fill="x", pady=(0, 14))
        ttk.Label(hdr_frame, text="Fire Station Command", style="Header.TLabel").pack(side="left")
        ttk.Label(hdr_frame, text="Crew Management Console", style="SubHeader.TLabel").pack(side="left", padx=12)

        content_frame = ttk.Frame(top_frame, style="Main.TFrame")
        content_frame.pack(fill="both", expand=True)

        left = ttk.Frame(content_frame, width=280, style="Panel.TFrame")
        left.pack(side="left", fill="y", padx=(0, 12))
        left.pack_propagate(False)

        right = ttk.Frame(content_frame, style="Panel.TFrame")
        right.pack(side="left", fill="both", expand=True)

        self._build_left_panel(left)

        self._build_right_panel(right)

        self.status_var = tk.StringVar(value="Loaded {} crew members".format(len(self.tracker.crew)))
        status = ttk.Label(self, textvariable=self.status_var, style="SubHeader.TLabel", anchor="w")
        status.pack(fill="x", padx=18, pady=(0, 12))

    def _build_left_panel(self, parent):
        title = ttk.Label(parent, text="Actions", style="SubHeader.TLabel")
        title.pack(anchor="w", padx=12, pady=(12, 8))

        btn_config = {"width": 26, "compound": "left"}

        def make_button(text, command, accent=ACCENT):
            b = tk.Button(parent, text=text, command=command,
                          bg=accent, fg=TEXT, font=("Segoe UI", 11, "bold"),
                          relief="flat", bd=0, activebackground=lighten(accent, 0.95),
                          padx=6, pady=8)
            b.pack(pady=8, padx=12)
            def on_enter(e, btn=b, c=accent):
                btn.configure(bg=lighten(c, BTN_HOVER_MULT))
            def on_leave(e, btn=b, c=accent):
                btn.configure(bg=c)
            b.bind("<Enter>", on_enter)
            b.bind("<Leave>", on_leave)
            return b

        make_button("➕  Add Firefighter", lambda: self.open_add_window())
        make_button("🚨  Dispatch Crew", lambda: self.open_dispatch_window())
        make_button("✏️  Edit / Delete Crew", lambda: self.open_edit_window())
        make_button("✅  Mark Available", lambda: self.open_mark_available_window())

        # info panel
        info_frame = ttk.Frame(parent, style="Panel.TFrame")
        info_frame.pack(side="bottom", fill="x", pady=12, padx=12)
        ttk.Label(info_frame, text="Quick Info", style="SubHeader.TLabel").pack(anchor="w", pady=8)
        self.total_var = tk.StringVar(value=f"Total Crew: {len(self.tracker.crew)}")
        ttk.Label(info_frame, textvariable=self.total_var, style="SubHeader.TLabel").pack(anchor="w")
        dispatched = len([f for f in self.tracker.crew if not f.get("available", True)])
        self.dispatched_var = tk.StringVar(value=f"Dispatched: {dispatched}")
        ttk.Label(info_frame, textvariable=self.dispatched_var, style="SubHeader.TLabel").pack(anchor="w")

    #  main list view
    def _build_right_panel(self, parent):
        # Search area
        search_frame = ttk.Frame(parent, style="Panel.TFrame")
        search_frame.pack(fill="x", padx=12, pady=12)

        ttk.Label(search_frame, text="Search:", style="SubHeader.TLabel").pack(side="left", padx=(4, 8))

        self.search_var = tk.StringVar()
        ent = ttk.Entry(search_frame, textvariable=self.search_var, width=30)
        ent.pack(side="left", padx=(0, 8))
        ent.bind("<Return>", lambda e: self.refresh_treeview())

        self.filter_expertise = tk.StringVar(value="All")
        combo = ttk.Combobox(search_frame, textvariable=self.filter_expertise, values=["All"] + EXPERTISE_OPTIONS, state="readonly", width=20)
        combo.pack(side="left", padx=(0, 8))
        combo.bind("<<ComboboxSelected>>", lambda e: self.refresh_treeview())

        btn_search = tk.Button(search_frame, text="Search", command=self.refresh_treeview, bg=ACCENT, fg=TEXT, relief="flat")
        btn_search.pack(side="left", padx=6)
        btn_reset = tk.Button(search_frame, text="Reset", command=self._reset_filters, bg="#444444", fg=TEXT, relief="flat")
        btn_reset.pack(side="left", padx=6)

        # Treeview
        cols = ("name", "id", "contact", "expertise", "status", "threat")
        tree_frame = ttk.Frame(parent, style="Panel.TFrame")
        tree_frame.pack(fill="both", expand=True, padx=12, pady=(0,12))

        self.tree = ttk.Treeview(tree_frame, columns=cols, show="headings", selectmode="browse")
        headings = {
            "name": "Name",
            "id": "ID",
            "contact": "Contact",
            "expertise": "Expertise",
            "status": "Status",
            "threat": "Threat / Location"
        }
        widths = {"name": 220, "id": 90, "contact": 150, "expertise": 150, "status": 100, "threat": 240}
        for c in cols:
            self.tree.heading(c, text=headings[c])
            self.tree.column(c, width=widths[c], anchor="w")

        scrollbar_y = ttk.Scrollbar(tree_frame, orient="vertical", command=self.tree.yview)
        scrollbar_x = ttk.Scrollbar(tree_frame, orient="horizontal", command=self.tree.xview)
        self.tree.configure(yscroll=scrollbar_y.set, xscroll=scrollbar_x.set)

        self.tree.pack(fill="both", expand=True, side="left")
        scrollbar_y.pack(side="left", fill="y")
        scrollbar_x.pack(side="bottom", fill="x")

        # Footer buttons for selected
        action_frame = ttk.Frame(parent, style="Panel.TFrame")
        action_frame.pack(fill="x", padx=12, pady=(0, 12))

        btn_view = tk.Button(action_frame, text="View Details", command=self._view_selected, bg="#2f2f2f", fg=TEXT, relief="flat")
        btn_view.pack(side="left", padx=6)
        btn_edit = tk.Button(action_frame, text="Edit Selected", command=self._edit_selected, bg=ACCENT, fg=TEXT, relief="flat")
        btn_edit.pack(side="left", padx=6)
        btn_delete = tk.Button(action_frame, text="Delete Selected", command=self._delete_selected, bg="#6b0000", fg=TEXT, relief="flat")
        btn_delete.pack(side="left", padx=6)
        btn_dispatch = tk.Button(action_frame, text="Dispatch Selected", command=self._dispatch_selected, bg=ACCENT, fg=TEXT, relief="flat")
        btn_dispatch.pack(side="right", padx=6)

        # initial fill
        self.refresh_treeview()

    # ---------- helpers ----------
    def _reset_filters(self):
        self.search_var.set("")
        self.filter_expertise.set("All")
        self.refresh_treeview()

    def refresh_treeview(self):
        q = self.search_var.get().strip().lower()
        expertise_filter = self.filter_expertise.get()
        # clear tree
        for r in self.tree.get_children():
            self.tree.delete(r)
        # filter
        def matches(f):
            if expertise_filter != "All" and f.get("expertise") != expertise_filter:
                return False
            if not q:
                return True
            # check name, id, contact, expertise
            return q in f.get("name", "").lower() or q in f.get("id", "").lower() or q in f.get("contact", "").lower() or q in f.get("expertise", "").lower()

        for idx, f in enumerate(self.tracker.crew):
            if not matches(f):
                continue
            status = "Available" if f.get("available", True) else "Dispatched"
            threat_str = ""
            if not f.get("available", True):
                tn = f.get("threat_name") or ""
                tl = f.get("threat_location") or ""
                threat_str = f"{tn} — {tl}"
            self.tree.insert("", "end", iid=str(idx),
                             values=(f.get("name", ""), f.get("id", ""), f.get("contact", ""),
                                     f.get("expertise", ""), status, threat_str))
        # update quick info
        self.total_var.set(f"Total Crew: {len(self.tracker.crew)}")
        dispatched = len([f for f in self.tracker.crew if not f.get("available", True)])
        self.dispatched_var.set(f"Dispatched: {dispatched}")
        self.status_var.set(f"Showing {len(self.tree.get_children())} records — Total {len(self.tracker.crew)}")

    def _get_selected_index(self):
        sel = self.tree.selection()
        if not sel:
            messagebox.showwarning("No selection", "Please select a record from the list.")
            return None
        return int(sel[0])

    # ---------- window actions ----------
    def open_add_window(self):
        w = tk.Toplevel(self)
        w.title("Add Firefighter")
        w.configure(bg=PANEL)
        w.geometry("460x360")
        w.resizable(False, False)

        frm = ttk.Frame(w, style="Panel.TFrame")
        frm.pack(fill="both", expand=True, padx=14, pady=14)

        ttk.Label(frm, text="Add New Firefighter", style="SubHeader.TLabel").pack(anchor="w", pady=(0,10))

        # fields
        entries = {}
        def add_field(label_text, row):
            lbl = ttk.Label(frm, text=label_text + ":", style="SubHeader.TLabel")
            lbl.pack(anchor="w", pady=(8,2))
            ent = ttk.Entry(frm)
            ent.pack(fill="x")
            return ent

        entry_name = add_field("Full Name", 0)
        entry_id = add_field("ID (8 digits)", 1)
        entry_contact = add_field("Contact", 2)

        ttk.Label(frm, text="Area of Expertise:", style="SubHeader.TLabel").pack(anchor="w", pady=(8,2))
        expertise_var = tk.StringVar()
        combo = ttk.Combobox(frm, textvariable=expertise_var, values=EXPERTISE_OPTIONS, state="readonly")
        combo.pack(fill="x")

        def on_confirm():
            name = entry_name.get().strip()
            idnum = entry_id.get().strip()
            contact = entry_contact.get().strip()
            expertise = expertise_var.get()
            if not (name and idnum and contact and expertise):
                messagebox.showerror("Missing Fields", "All fields are required.")
                return
            if len(idnum) != 8 or not idnum.isdigit():
                messagebox.showerror("Invalid ID", "ID must be exactly 8 digits.")
                return
            for f in self.tracker.crew:
                if f.get("id") == idnum:
                    messagebox.showerror("Duplicate ID", "This ID already exists.")
                    return
            newff = {
                "name": name,
                "id": idnum,
                "contact": contact,
                "expertise": expertise,
                "available": True,
                "threat_name": None,
                "threat_location": None
            }
            self.tracker.add_firefighter(newff)
            messagebox.showinfo("Added", f"{name} added to crew.")
            w.destroy()
            self.refresh_treeview()

        btn = tk.Button(frm, text="Add Firefighter", command=on_confirm, bg=ACCENT, fg=TEXT, relief="flat")
        btn.pack(pady=12)

    def open_view_window(self):
        #  refresh
        self.refresh_treeview()
        messagebox.showinfo("View Crew", "Use the main list to view and search crew records.")

    def open_dispatch_window(self):
        # popup that lists available crew and allows dispatching
        w = tk.Toplevel(self)
        w.title("Dispatch Crew")
        w.configure(bg=PANEL)
        w.geometry("600x420")

        frm = ttk.Frame(w, style="Panel.TFrame")
        frm.pack(fill="both", expand=True, padx=12, pady=12)

        ttk.Label(frm, text="Dispatch Available Crew", style="SubHeader.TLabel").pack(anchor="w", pady=(0,8))

        list_frame = ttk.Frame(frm, style="Panel.TFrame")
        list_frame.pack(fill="both", expand=True)

        canvas = tk.Canvas(list_frame, bg=PANEL, highlightthickness=0)
        scroll = ttk.Scrollbar(list_frame, orient="vertical", command=canvas.yview)
        inner = ttk.Frame(canvas, style="Panel.TFrame")
        inner.bind("<Configure>", lambda e: canvas.configure(scrollregion=canvas.bbox("all")))
        canvas.create_window((0,0), window=inner, anchor="nw")
        canvas.configure(yscrollcommand=scroll.set)
        canvas.pack(side="left", fill="both", expand=True)
        scroll.pack(side="right", fill="y")

        available = [(i,f) for i,f in enumerate(self.tracker.crew) if f.get("available", True)]
        if not available:
            ttk.Label(inner, text="No available firefighters at the moment.", style="SubHeader.TLabel").pack(pady=14)
        else:
            for idx, ff in available:
                row = ttk.Frame(inner, style="Panel.TFrame")
                row.pack(fill="x", pady=6, padx=6)
                lbl = ttk.Label(row, text=f"{ff['name']} — {ff['expertise']} — {ff['contact']}", style="SubHeader.TLabel")
                lbl.pack(side="left")
                def make_dispatch(i=idx):
                    self._popup_dispatch(i, parent_window=w, refresh_cb=self.refresh_treeview)
                btn = tk.Button(row, text="Dispatch", command=make_dispatch, bg="#aa2b1f", fg=TEXT, relief="flat")
                btn.pack(side="right")

    def _popup_dispatch(self, idx, parent_window=None, refresh_cb=None):
        popup = tk.Toplevel(parent_window or self)
        popup.title("Dispatch Details")
        popup.configure(bg=PANEL)
        popup.geometry("420x220")
        frm = ttk.Frame(popup, style="Panel.TFrame")
        frm.pack(fill="both", expand=True, padx=12, pady=12)

        ttk.Label(frm, text=f"Dispatching: {self.tracker.crew[idx]['name']}", style="SubHeader.TLabel").pack(anchor="w")
        ttk.Label(frm, text="Threat Name:", style="SubHeader.TLabel").pack(anchor="w", pady=(8,2))
        ent_thr = ttk.Entry(frm)
        ent_thr.pack(fill="x")
        ttk.Label(frm, text="Threat Location:", style="SubHeader.TLabel").pack(anchor="w", pady=(8,2))
        ent_loc = ttk.Entry(frm)
        ent_loc.pack(fill="x")

        def confirm():
            threat = ent_thr.get().strip()
            loc = ent_loc.get().strip()
            if not (threat and loc):
                messagebox.showerror("Missing", "Both threat name and location are required.")
                return
            self.tracker.crew[idx]["available"] = False
            self.tracker.crew[idx]["threat_name"] = threat
            self.tracker.crew[idx]["threat_location"] = loc
            self.tracker.save_crew()
            messagebox.showinfo("Dispatched", f"{self.tracker.crew[idx]['name']} dispatched.")
            popup.destroy()
            if refresh_cb:
                refresh_cb()

        btn = tk.Button(frm, text="Confirm Dispatch", command=confirm, bg=ACCENT, fg=TEXT, relief="flat")
        btn.pack(pady=10)

    def open_edit_window(self):
        sel = self._get_selected_index()
        if sel is None:
            return
        self._open_edit_popup(sel)

    def _edit_selected(self):
        sel = self._get_selected_index()
        if sel is None:
            return
        self._open_edit_popup(sel)

    def _open_edit_popup(self, idx):
        ff = self.tracker.crew[idx]
        popup = tk.Toplevel(self)
        popup.title("Edit Firefighter")
        popup.configure(bg=PANEL)
        popup.geometry("460x380")

        frm = ttk.Frame(popup, style="Panel.TFrame")
        frm.pack(fill="both", expand=True, padx=12, pady=12)

        ttk.Label(frm, text=f"Editing: {ff['name']}", style="SubHeader.TLabel").pack(anchor="w", pady=(0,8))

        ttk.Label(frm, text="Full Name:", style="SubHeader.TLabel").pack(anchor="w", pady=(8,2))
        ent_name = ttk.Entry(frm)
        ent_name.insert(0, ff.get("name", ""))
        ent_name.pack(fill="x")

        ttk.Label(frm, text="ID (8 digits):", style="SubHeader.TLabel").pack(anchor="w", pady=(8,2))
        ent_id = ttk.Entry(frm)
        ent_id.insert(0, ff.get("id", ""))
        ent_id.pack(fill="x")

        ttk.Label(frm, text="Contact:", style="SubHeader.TLabel").pack(anchor="w", pady=(8,2))
        ent_contact = ttk.Entry(frm)
        ent_contact.insert(0, ff.get("contact", ""))
        ent_contact.pack(fill="x")

        ttk.Label(frm, text="Expertise:", style="SubHeader.TLabel").pack(anchor="w", pady=(8,2))
        exp_var = tk.StringVar(value=ff.get("expertise", EXPERTISE_OPTIONS[0]))
        combo = ttk.Combobox(frm, textvariable=exp_var, values=EXPERTISE_OPTIONS, state="readonly")
        combo.pack(fill="x")

        def confirm_edit():
            name = ent_name.get().strip()
            idnum = ent_id.get().strip()
            contact = ent_contact.get().strip()
            expertise = exp_var.get()
            if not (name and idnum and contact and expertise):
                messagebox.showerror("Missing Fields", "All fields are required.")
                return
            if len(idnum) != 8 or not idnum.isdigit():
                messagebox.showerror("Invalid ID", "ID must be exactly 8 digits.")
                return
            for i, other in enumerate(self.tracker.crew):
                if i != idx and other.get("id") == idnum:
                    messagebox.showerror("Duplicate ID", "Another entry uses this ID.")
                    return
            # preserve availability + threat data
            self.tracker.crew[idx].update({
                "name": name,
                "id": idnum,
                "contact": contact,
                "expertise": expertise
            })
            self.tracker.save_crew()
            messagebox.showinfo("Saved", "Firefighter record updated.")
            popup.destroy()
            self.refresh_treeview()

        btn = tk.Button(frm, text="Save Changes", command=confirm_edit, bg=ACCENT, fg=TEXT, relief="flat")
        btn.pack(pady=10)

    def _view_selected(self):
        sel = self._get_selected_index()
        if sel is None:
            return
        ff = self.tracker.crew[sel]
        popup = tk.Toplevel(self)
        popup.title("Firefighter Details")
        popup.configure(bg=PANEL)
        popup.geometry("480x320")

        frm = ttk.Frame(popup, style="Panel.TFrame")
        frm.pack(fill="both", expand=True, padx=12, pady=12)

        lines = [
            ("Name:", ff.get("name", "")),
            ("ID:", ff.get("id", "")),
            ("Contact:", ff.get("contact", "")),
            ("Expertise:", ff.get("expertise", "")),
            ("Status:", "Available" if ff.get("available", True) else "Dispatched"),
        ]
        for k, v in lines:
            ttk.Label(frm, text=k, style="SubHeader.TLabel").pack(anchor="w", pady=(8,0))
            ttk.Label(frm, text=v, style="SubHeader.TLabel").pack(anchor="w")

        if not ff.get("available", True):
            ttk.Label(frm, text="Threat:", style="SubHeader.TLabel").pack(anchor="w", pady=(8,0))
            ttk.Label(frm, text=ff.get("threat_name", "") or "-", style="SubHeader.TLabel").pack(anchor="w")
            ttk.Label(frm, text="Location:", style="SubHeader.TLabel").pack(anchor="w", pady=(8,0))
            ttk.Label(frm, text=ff.get("threat_location", "") or "-", style="SubHeader.TLabel").pack(anchor="w")

    def _delete_selected(self):
        sel = self._get_selected_index()
        if sel is None:
            return
        ff = self.tracker.crew[sel]
        if not messagebox.askyesno("Confirm Delete", f"Delete {ff.get('name')}? This cannot be undone."):
            return
        self.tracker.delete_firefighter(sel)
        self.refresh_treeview()

    def _dispatch_selected(self):
        sel = self._get_selected_index()
        if sel is None:
            return
        ff = self.tracker.crew[sel]
        if not ff.get("available", True):
            messagebox.showwarning("Already Dispatched", f"{ff.get('name')} is already dispatched.")
            return
        self._popup_dispatch(sel, parent_window=self, refresh_cb=self.refresh_treeview)

    def open_mark_available_window(self):
        w = tk.Toplevel(self)
        w.title("Mark as Available")
        w.configure(bg=PANEL)
        w.geometry("520x380")

        frm = ttk.Frame(w, style="Panel.TFrame")
        frm.pack(fill="both", expand=True, padx=12, pady=12)
        ttk.Label(frm, text="Marked Unavailable Crew", style="SubHeader.TLabel").pack(anchor="w", pady=(0,8))

        list_frame = ttk.Frame(frm, style="Panel.TFrame")
        list_frame.pack(fill="both", expand=True)

        canvas = tk.Canvas(list_frame, bg=PANEL, highlightthickness=0)
        scroll = ttk.Scrollbar(list_frame, orient="vertical", command=canvas.yview)
        inner = ttk.Frame(canvas, style="Panel.TFrame")
        inner.bind("<Configure>", lambda e: canvas.configure(scrollregion=canvas.bbox("all")))
        canvas.create_window((0,0), window=inner, anchor="nw")
        canvas.configure(yscrollcommand=scroll.set)
        canvas.pack(side="left", fill="both", expand=True)
        scroll.pack(side="right", fill="y")

        unavailable = [(i,f) for i,f in enumerate(self.tracker.crew) if not f.get("available", True)]
        if not unavailable:
            ttk.Label(inner, text="No currently dispatched / unavailable firefighters.", style="SubHeader.TLabel").pack(pady=14)
        else:
            for idx, ff in unavailable:
                row = ttk.Frame(inner, style="Panel.TFrame")
                row.pack(fill="x", pady=6, padx=6)
                lbl = ttk.Label(row, text=f"{ff['name']} — {ff['threat_name'] or '-'} @ {ff['threat_location'] or '-'}", style="SubHeader.TLabel")
                lbl.pack(side="left")
                def make_mark(i=idx):
                    self.tracker.crew[i]["available"] = True
                    self.tracker.crew[i]["threat_name"] = None
                    self.tracker.crew[i]["threat_location"] = None
                    self.tracker.save_crew()
                    self.refresh_treeview()
                    # refresh the popup content by destroying and reopening
                    w.destroy()
                    self.open_mark_available_window()
                btn = tk.Button(row, text="Mark Available", command=make_mark, bg="#2a8f47", fg=TEXT, relief="flat")
                btn.pack(side="right")
# Run app
if __name__ == "__main__":
    app = FireStationApp()
    app.mainloop()
