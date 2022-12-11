from gauss_expert import *

WIDTH = 960
HEIGHT = 540
CENTER = int(WIDTH / 2) - 100

dpg.create_context()

ge = GaussExpert()
print(ge.gauss_parametrs)

# region WINDOW#1: Simple Decision Support System
with dpg.window(label="Simple Decision Support System", tag="Main"):
    # Справочная информация
    dpg.add_child_window(tag='info', height=380)
    # Ввод альтернатив
    with dpg.group(horizontal=True):
        dpg.add_text(default_value='Количество альтернатив: ')
        dpg.add_input_int(tag='alts', default_value=2, min_value=2, min_clamped=True)
    # Ввод критериев
    with dpg.group(horizontal=True):
        with dpg.group(horizontal=False):
            dpg.add_text(default_value='Название критерия #1: ')
            dpg.add_text(default_value='Название критерия #2: ')
        with dpg.group(horizontal=False):
            dpg.add_input_text(tag='crit1', default_value='Критерий #1')
            dpg.add_input_text(tag='crit2', default_value='Критерий #2')
    dpg.add_button(label='Подтвердить', indent=CENTER,
                   callback=lambda: dpg.configure_item('gauss_param', show=True))


# endregion

# region WINDOW#2: Gauss Parameters (with check)
def switch_crit(sender, app_data, crit):
    if check_inputs(crit):
        if crit == 0:
            dpg.delete_item(f'child{crit}')
            dpg.configure_item(f'child{crit + 1}', show=True)
        else:
            dpg.delete_item('gauss_param')
            dpg.configure_item('window_alter', show=True)
            window_alter(ge.alts)


def check_inputs(crit):
    itsok = True
    if dpg.get_value(f'a1_crit{crit}') >= dpg.get_value(f'a2_crit{crit}'):
        dpg.configure_item(f'a2_crit{crit}_except', show=True)
        dpg.set_value(f'a2_crit{crit}_except', 'Значение Ay2 должно быть больше значения Ay1')
        itsok = False
    if dpg.get_value(f'a2_crit{crit}') >= dpg.get_value(f'a3_crit{crit}'):
        dpg.configure_item(f'a3_crit{crit}_except', show=True)
        dpg.set_value(f'a3_crit{crit}_except', 'Значение должно быть больше Ay1 и Ay2')
        itsok = False
    if dpg.get_value(f'j1_crit{crit}') <= dpg.get_value(f'a1_crit{crit}') \
            or dpg.get_value(f'j1_crit{crit}') >= dpg.get_value(f'a2_crit{crit}'):
        dpg.configure_item(f'j1_crit{crit}_except', show=True)
        dpg.set_value(f'j1_crit{crit}_except', 'Значение должно быть между Ay1 и Ay2')
        itsok = False
    if dpg.get_value(f'j2_crit{crit}') <= dpg.get_value(f'a2_crit{crit}') \
            or dpg.get_value(f'j2_crit{crit}') >= dpg.get_value(f'a3_crit{crit}'):
        dpg.configure_item(f'j2_crit{crit}_except', show=True)
        dpg.set_value(f'j2_crit{crit}_except', 'Значение должно быть между Ay2 и Ay3')
        itsok = False
    itsok = True  # ЗАГЛУШКА
    if itsok:
        for i in range(2):
            ge.gauss_parametrs[crit]['dominant_value'][i] = dpg.get_value(f'a{i + 1}_crit{crit}')
            ge.gauss_parametrs[crit]['bound_neighb'][i] = dpg.get_value(f'j{i + 1}_crit{crit}')
            ge.gauss_parametrs[crit]['membership_deg'][i] = dpg.get_value(f'M{i + 1}_crit{crit}')
        ge.gauss_parametrs[crit]['dominant_value'][2] = dpg.get_value(f'a3_crit{crit}')
        ge.crits = 2
        ge.alts = dpg.get_value('alts')
    return itsok


# region WINDOW#2: Gauss Parameters
with dpg.window(label="Gauss Parameters", tag="gauss_param", width=WIDTH, height=HEIGHT,
                show=False, no_move=True, no_resize=True, modal=True):
    for i in range(2):
        with dpg.child_window(tag=f'child{i}', show=False):
            dpg.add_text(default_value=f'Параметры функции Гаусса для критерия #{i + 1}', indent=CENTER - 120)
            dpg.add_separator()
            # Ввод доминирующих значений
            dpg.add_text(default_value='Доминирующее значение Y нечёткого множества, описывающего терм, ai')
            with dpg.group(horizontal=False):
                for j in range(3):
                    with dpg.group(horizontal=True):
                        dpg.add_text(default_value=f'Ay{j + 1}: ')
                        dpg.add_input_double(tag=f'a{j + 1}_crit{i}', default_value=0, width=150)
                        dpg.add_input_text(tag=f'a{j + 1}_crit{i}_except', show=False)

            dpg.add_separator()
            # Ввод пограничных значений
            dpg.add_text(default_value='Пограничные значения соседних термов, j')
            with dpg.group(horizontal=False):
                for j in range(2):
                    with dpg.group(horizontal=True):
                        dpg.add_text(default_value=f'j{j + 1}: ')
                        dpg.add_input_double(tag=f'j{j + 1}_crit{i}', default_value=0, width=150)
                        dpg.add_input_text(tag=f'j{j + 1}_crit{i}_except', show=False)
            dpg.add_separator()
            # Ввод степени разделения
            dpg.add_text(default_value='Степень принадлежности пограничных значений(степень разделения), М')
            with dpg.group(horizontal=False):
                for j in range(2):
                    with dpg.group(horizontal=True):
                        dpg.add_text(default_value=f'M{j + 1}: ')
                        dpg.add_input_double(tag=f'M{j + 1}_crit{i}', default_value=0, width=150,
                                             min_value=0.0, min_clamped=True, max_value=1.0, max_clamped=True)
                        dpg.add_input_text(tag=f'M{j + 1}_crit{i}_except', show=False)
            dpg.add_button(label='Подтвердить', indent=CENTER,
                           callback=switch_crit, user_data=i)
        dpg.configure_item('child0', show=True)

# endregion
# endregion


# region WINDOW#3: Input Alternatives
def switch_grade():
    if check_crit():
        dpg.configure_item('window_gauss_grade', show=True)
    else:
        dpg.configure_item('window_exc', show=True)


def check_crit():
    succ = True
    for alter in range(ge.alts):
        for crit in range(ge.crits):
            if dpg.get_value(f'alt{alter}_crit{crit+1}') < ge.gauss_parametrs[crit]['dominant_value'][0] \
                  or dpg.get_value(f'alt{alter}_crit{crit+1}') > ge.gauss_parametrs[crit]['dominant_value'][2]:
                print("ERROR")
                dpg.add_text(default_value=f'Error: значение альтернативы {alter+1} критерия {crit+1} неверно', parent='window_exc')
                succ = False
    return succ


with dpg.window(label='Предупреждение', tag="window_exc", width=WIDTH, height=HEIGHT,
                show=False, no_move=True, no_resize=True):
    pass


with dpg.window(label="Input Alternatives", tag="window_alter", width=WIDTH, height=HEIGHT,
                show=False, no_move=True, no_resize=True):
    # Ввод альтернатив
    dpg.add_table(tag='table_alts',
                  resizable=True, policy=dpg.mvTable_SizingStretchProp,
                  row_background=True, header_row=False,
                  borders_innerH=True, borders_outerH=True, borders_innerV=True,
                  borders_outerV=True)
    dpg.add_button(label='Продолжить', indent=CENTER, callback=switch_grade)


def window_alter(amount_alts):
    print(ge.gauss_parametrs)
    dpg.add_table_column(parent='table_alts')
    dpg.add_table_column(parent='table_alts')
    for i in range(dpg.get_value('alts')):
        with dpg.table_row(parent='table_alts'):
            dpg.add_text(default_value=f'Альтернатива #{i + 1}')
            dpg.add_input_text(tag=f'alt{i}_text', hint=f'Ввод альтернативы #{i + 1}')
        with dpg.table_row(parent='table_alts'):
            dpg.add_text(default_value=dpg.get_value('crit1'))
            dpg.add_input_float(tag=f'alt{i}_crit1')
        with dpg.table_row(parent='table_alts'):
            dpg.add_text(default_value=dpg.get_value('crit2'))
            dpg.add_input_float(tag=f'alt{i}_crit2')



# endregion

# region WINDOW#4: Gauss Criteria Grade
with dpg.window(label="Gauss Criteria Grade", tag="window_gauss_grade", width=WIDTH, height=HEIGHT,
                show=False, no_move=True, no_resize=True):
    # Ввод альтернатив
    pass






# endregion

# region Gauss Criteria Estimate
with dpg.window(label='Gauss Criteria Estimate', popup=True, tag="window_gauss_est", width=WIDTH, height=HEIGHT,
                show=False, no_move=True, no_resize=True):
    pass

# endregion

# region other
def on_exit(sender, app_data, user_data):
    print("closed")


with dpg.font_registry():
    with dpg.font(f'/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf', 20, default_font=True, id="Default font"):
        dpg.add_font_range_hint(dpg.mvFontRangeHint_Cyrillic)
dpg.bind_font("Default font")

########################################################################################################################
dpg.create_viewport(title='НЕЧЁТКОЕ МНОГОКРИТЕРИАЛЬНОЕ ОЦЕНИВАНИЕ МЕТОДОМ ГАУССА', width=WIDTH, height=HEIGHT,
                    resizable=False)
dpg.set_global_font_scale(1.25)
dpg.set_exit_callback(on_exit)
dpg.setup_dearpygui()
dpg.show_viewport()
dpg.set_primary_window("Main", True)
dpg.start_dearpygui()
dpg.destroy_context()
# endregion
